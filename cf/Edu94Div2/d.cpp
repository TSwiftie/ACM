#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int N = 3e3+10;
int a[N],n,t,pre[N][N],suf[N][N];
void solve(){
    scanf("%lld",&n);
    for(int i = 1;i <= n;++i) { scanf("%lld",a+i);++pre[i][a[i]];++suf[i][a[i]]; }
    for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) pre[i][j] += pre[i-1][j];
    for(int i = n;i >= 1;--i) for(int j = 1;j <= n;++j) suf[i][j] += suf[i+1][j];
    int ans = 0;
    for(int j = 1;j <= n;++j) for(int k = j+1;k <= n;++k) ans += pre[j-1][a[k]]*suf[k+1][a[j]];
    printf("%lld\n",ans);
    memset(pre,0,sizeof pre);memset(suf,0,sizeof suf);
}
signed main(void){
    for(scanf("%lld",&t);t--;) solve();
    return 0;
}
