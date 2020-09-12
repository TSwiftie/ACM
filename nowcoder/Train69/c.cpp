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
struct edge{ int u,v,w; }es[N<<1];
int n,m,cnt,f[N],ans;
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
signed main(void){
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;++i) f[i] = i;
    for(int i = 1;i <= m;++i) cin >> es[i].u >> es[i].v >> es[i].w;
    sort(es+1,es+1+m,[](edge a,edge b){ return a.w > b.w; });
    for(int i = 1;i <= m;++i){
        int u = es[i].u,v = es[i].v,w = es[i].w;
        int fu = find(u),fv = find(v);
        if(fu!=fv){ f[fv] = fu;ans+=w;++cnt; }
        if(cnt==n-1) break;
    }
    printf("%lld\n",ans);
    return 0;
}
