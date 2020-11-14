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
const int N = 5e5+10;
vi G[N];
vector<pii> Q[N];
int n,m,ans[N],siz[N],son[N],dep[N],w[N],cnt[N][30],nowson;
void add(int u,int v){ G[u].push_back(v);G[v].push_back(u); }
void dfs(int u,int f){
    siz[u] = 1;dep[u] = dep[f] + 1;
    for(int v : G[u]) if(v != f){
        dfs(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}
void calc(int u,int val){
    cnt[dep[u]][w[u]] += val;
    for(int v : G[u]) if(v != nowson)
        calc(v,val);
}
void dsu(int u,bool keep){
    for(int v : G[u]) if(v != son[u]) dsu(v,0);
    if(son[u]) dsu(son[u],1),nowson = son[u];
    calc(u,1);
    for(int i = 0,t,id,d;i < SZ(Q[u]);++i){
        id = Q[u][i].first,d = Q[u][i].second,t = 0;
        for(int j = 0;j < 26;++j)
            if(cnt[d][j] & 1) ++t;
        ans[id] = t > 1 ? 0 : 1;
    }
    nowson = 0;
    if(!keep) calc(u,-1);
}
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 2,f;i <= n;++i) scanf("%d",&f),G[f].push_back(i);
    char ch;for(int i = 1;i <= n;++i) cin >> ch,w[i] = ch-'a';
    dfs(1,0);
    for(int i = 1,u,v;i <= m;++i) scanf("%d%d",&u,&v),Q[u].push_back({i,v});
    dsu(1,1);
    for(int i = 1;i <= m;++i) printf("%s\n",ans[i]?"Yes":"No");
    return 0;
}
