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
const int N = 3e5+10;
const int M = 1e6+10;
int n, m, fa[N], ans[N];vi G[N];
signed main(void){
    IOS;int t;cin >> t;for(int cas = 1;cas <= t;++cas){
        cin >> n >> m;
        for(int i = 1,u,v;i <= m;++i){
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    return 0;
}
