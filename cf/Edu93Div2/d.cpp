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
const int N = 210;
int r[N],g[N],b[N],R,G,B,ans,dp[N][N][N];
signed main(void){
    scanf("%d%d%d",&R,&G,&B);
    for(int i = 1;i <= R;++i) scanf("%d",r+i);
    for(int i = 1;i <= G;++i) scanf("%d",g+i);
    for(int i = 1;i <= B;++i) scanf("%d",b+i);
    sort(r+1,r+1+R);sort(g+1,g+1+G);sort(b,b+1+B);
    for(int i = R;i >= 0;--i)
        for(int j = G;j >= 0;--j)
            for(int k = 0;k <= B;++k){
                dp[i][j][k] = max(dp[i+1][j+1][k]+r[i+1]*g[j+1],max(dp[i+1][j][k+1]+r[i+1]*b[k+1],max(dp[i][j+1][k+1]+g[j+1]*b[k+1],0)));
                ans = max(ans,dp[i][j][k]);
            }
    printf("%d\n",ans);
    return 0;
}
