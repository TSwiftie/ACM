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
const int N = 5e6+10;
vi G[N];int n, dep[N];
void dfs1(int u,int f){
    dep[u] = dep[f] + 1;
    for(int v : G[u]) if(v!=f){
        dfs1(v,u);
    }
}
signed main(void){
    int t;cin >> t;for(int cas = 1;cas <= t;++cas){
        cin >> n;for(int i = 2,u;i <= n;++i){
            cin >> u;G[u].push_back(i);
            G[i].push_back(u);
        }
        dfs1(1,0);
    }
    return 0;
}
