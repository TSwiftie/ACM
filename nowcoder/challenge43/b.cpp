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
const int N = 1e5+10;
const int mod = 998244353;
int ksm(int a,int b,int res = 1){ for(;b;b >>= 1,a = a * a % mod) if(b&1) res = res * a % mod; return res; }
int n, m, ans;
int p[N] = {1};
signed main(void){
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <= n;++i) p[i] = p[i-1] * i % mod;
    for(int i = 0;i <= m+1;++i) ans = (ans + p[n]*ksm(p[i],mod-2)%mod*ksm(p[n-i],mod-2)%mod)%mod;
    printf("%lld\n",ans);
    return 0;
}
