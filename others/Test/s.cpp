#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const char *INPUT = "/home/ts/code/in.in";
const int N = 1e2+10;
int n, m, du[N], id[N], buc[N], cnt;vi G[N];
void solve(){
    scanf("%d%d",&n,&m);
    for(int i = 1,u,v;i <= m;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        ++du[v];
    }
    queue<int>q;
    cnt = 1;
    for(int i = 1;i <= n;++i){
        if(!du[i]) q.push(i),id[i] = cnt,++buc[cnt];
    }
    while(q.size()){
        int sz = q.size();
        buc[++cnt] = sz;
        while(sz--){
            int u = q.front();q.pop();
            id[u] = cnt;
            for(int v : G[u]) if(!--du[v]){
                q.push(v);
            }
        }
    }
    int ans = 1;
    for(int i = 1;i <= cnt;++i) ans = max(ans,buc[i]);
    printf("%d\n",ans);
    memset(du,0,sizeof du);memset(buc,0,sizeof buc);
    for(int i = 1;i <= n;++i) G[i].clear();
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
