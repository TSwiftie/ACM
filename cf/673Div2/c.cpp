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
int n,len,dp[N];vi e[N];
void solve(){
    scanf("%d",&n);for(int i = 1,x;i <= n;++i) scanf("%d",&x),dp[i]=N,e[x].push_back(i);
    dp[0] = N;
    for(int i = 1;i <= n;++i) if(SZ(e[i])){
        len = 0;
        for(int j = 1;j < SZ(e[i]);++j)
            len = max(len,e[i][j]-e[i][j-1]);
        len = max({e[i][0],n-e[i].back()+1,len});
        dp[len] = min(dp[len],i);
    }
    for(int i = 1;i <= n;++i) printf("%d ",(dp[i]=min(dp[i],dp[i-1]))==N?-1:dp[i]);puts("");
    for(int i = 1;i <= n;++i) e[i].clear();
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
