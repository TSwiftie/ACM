#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int N = 5e5+10;
int f[N],dep[N],siz[N],n,ans,s;vi G[N];
void dfs(int u,int fa){
    siz[u] = 1;dep[u] = dep[fa] + 1;
    for(int v : G[u]){ dfs(v,u);siz[u] += siz[v]; }
    s += siz[u];
}
void dfs1(int u,int x){
    ans = max(ans,x);
    for(int v : G[u]) dfs1(v,x+(n-siz[v]));
}
void solve(){
    scanf("%lld",&n);for(int i = 2;i <= n;++i) scanf("%lld",f+i),G[f[i]].push_back(i);
    ans = s = 0;dfs(1,0),dfs1(1,s);
    printf("%lld\n",ans);
    for(int i = 1;i <= n;++i) G[i].clear(),f[i] = 0;
}
signed main(void){
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
