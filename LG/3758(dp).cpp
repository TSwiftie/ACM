#pragma GCC optimize(2)
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
const int N = 39,M = 109;
vi G[N];
void add_edge(int u,int v){ G[u].push_back(v); }
int n, m, t, f[1000006][32], ans;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1,u,v;i <= m;++i) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    scanf("%d",&t);
    for(int i = 1;i <= n;++i) add_edge(i,n+1),add_edge(i,i); f[0][1] = 1;add_edge(n+1, n+1);
    for(int i = 0;i <= t;++i)
        for(int u = 1;u <= n+1;++u)
            for(int v : G[u]) f[i+1][v] = (f[i+1][v] + f[i][u]) % 2017;
    for(int i = 1;i <= n+1;++i) ans = (ans + f[t][i]) % 2017;
    printf("%d\n",ans);
    return 0;
}
