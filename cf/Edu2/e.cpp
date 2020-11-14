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
vi G[N];
int col[N],n,u,v,cnt[N],maxx,nowson;
ll ans[N],sum[N];
int siz[N],son[N];
void dfs(int u,int f){
    siz[u] = 1;
    for(int v : G[u]) if(v != f){
        dfs(v,u);
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v]) son[u] = v;
    }
}
void add(int u,int f,int val){
    sum[cnt[col[u]]] -= col[u];
    cnt[col[u]] += val;
    sum[cnt[col[u]]] += col[u];
    if(cnt[col[u]] > maxx) maxx = cnt[col[u]];
    if(!sum[maxx]) maxx = cnt[col[u]];
    for(int v : G[u]) if(v != f && v != nowson)
        add(v,u,val);
}
void dsu(int u,int f,bool keep){
    for(int v : G[u]) if(v != f && v != son[u])
        dsu(v,u,0);
    if(son[u]) dsu(son[u],u,1),nowson = son[u];
    add(u,f,1);
    ans[u] = sum[maxx];
    nowson = 0;
    if(!keep) add(u,f,-1);
}
signed main(void){
    scanf("%d",&n);for(int i = 1;i <= n;++i) scanf("%d",col+i);
    for(int i = 1;i < n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0); dsu(1,0,1);
    for(int i = 1;i <= n;++i) printf("%lld%c",ans[i]," \n"[i==n]);
    return 0;
}
