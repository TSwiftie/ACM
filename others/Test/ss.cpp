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
const int N = 500;
int link[N],vis[N],g[N][N],n,m;
void floyd(){
    for(int k = 1;k <= n;++k)
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
                g[i][j] |= g[i][k] & g[k][j];
}
bool dfs(int u){
    for(int v = 1;v <= n;++v){
        if(vis[v]) continue;
        if(!g[u][v]) continue;
        vis[v] = 1;
        if(!link[v] || dfs(link[v])){
            link[v] = u;
            return true;
        }
    }
    return false;
}
void solve(){
    scanf("%d%d",&n,&m);
    for(int i = 1,u,v;i <= m;++i){
        scanf("%d%d",&u,&v);
        g[u][v] = 1;
    }
    floyd();
    int ans = 0;
    for(int i = 1;i <= n;++i){
        memset(vis,0,sizeof vis);
        if(dfs(i)) ++ans;
    }
    printf("%d\n",n-ans);
    memset(link,0,sizeof link);
    memset(g,0,sizeof g);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
