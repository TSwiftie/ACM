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
const int N = 25;
ll dp[N][N];
signed main(void){
    for(int i = 1;i <= 20;++i) dp[i][0] = dp[0][i] = 1;
    for(int i = 1;i <= 20;++i)
        for(int j = 1;j <= 20;++j)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    printf("%lld\n",dp[20][20]);
    return 0;
}
