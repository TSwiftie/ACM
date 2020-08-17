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
const int N = 2e5+10;
int a[N], n, k;
void solve(){
    int Max1 = -INF,Max2 = -INF;
    scanf("%lld%lld",&n,&k);for(int i = 1;i <= n;++i) scanf("%lld",a+i),Max1 = max(Max1,a[i]);
    for(int i = 1;i <= n;++i) a[i] = Max1-a[i],Max2 = max(Max2,a[i]);--k;
    if(k&1) for(int i = 1;i <= n;++i) printf("%lld%c",Max2-a[i]," \n"[i==n]);
    else for(int i = 1;i <= n;++i) printf("%lld%c",a[i]," \n"[i==n]);
}
signed main(void){
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
