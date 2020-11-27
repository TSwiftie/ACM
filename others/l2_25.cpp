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
const int N = 1e4+10;
int n, m;vi G[N];int ask[N],dig[N];
signed main(void){
    IOS;cin >> n >> m;
    for(int i = 1,u,v;i <= m;++i){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++dig[u];++dig[v];
    }
    int k;cin >> k;
    while(k--){
        int cnt;cin >> cnt;
        for(int i = 1;i <= cnt;++i){
            cin >> ask[i];
            dig[ask[i]] = 0;
        }
        for(int i = 1;i <= cnt;++i)
            for(int v : G[ask[i]]) if(dig[v]!=0) --dig[v];
        bool ok = true;
        for(int i = 1;i <= n;++i) if(dig[i]!=0) { ok = false;break; }
        cout << (ok ? "YES":"NO") << endl;
        for(int i = 1;i <= n;++i) if(dig[i]!=G[i].size()) dig[i] = G[i].size();
    }
    return 0;
}
