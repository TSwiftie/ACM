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
int n, m, block;vi G[N];bool vis[N];
void dfs(int u,int f){
    vis[u] = true;
    for(int v : G[u]) if (v!=f && !vis[v]) dfs(v,u);
}
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1,u,v;i <= m;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1;i <= n;++i){
        if(!vis[i]){
            ++block;
            dfs(i,0);
        }
    }
    printf("%d\n",block-1);
    return 0;
}
