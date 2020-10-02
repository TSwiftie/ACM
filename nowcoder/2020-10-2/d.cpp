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
const int N = 1e5+10;
struct Edge{ int u,v,w; }edge[N];int f[N];
bool cmp(Edge &a,Edge &b){ return a.w < b.w; }
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
void solve(int cas){
    int n, m;scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) f[i] = i;
    for(int i = 1;i <= m;++i){ scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w); }
    sort(edge+1,edge+m+1,cmp);
    int cnt = 0,ans = 0;
    for(int i = 1;i <= m;++i){
        int u = edge[i].u,v = edge[i].v,w = edge[i].w;
        int fu = find(u),fv = find(v);
        if(fu!=fv){ f[fv] = fu;++cnt;ans += w; }
    }
    printf("Case #%d: %d meters\n",cas,ans);
}
signed main(void){
    int t,cas = 0;for(scanf("%d",&t);t--;) solve(++cas);
    return 0;
}
