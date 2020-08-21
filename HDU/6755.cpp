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
const int N = 1e5+10;
const int mod = 1e9+9;
int fac[N+10],inv[N+10];
int ksm(int a,int b){
    int res = 1;a %= mod;
    if(b > mod) b = b%(mod-1) + mod - 1;
    for(;b;a = a * a % mod,b >>= 1) if(b&1) res = res * a % mod;
    return res;
}
void init(){
    fac[0] = 1;
    for(int i = 1;i <= N;++i) fac[i] = fac[i-1] * i % mod;
    inv[N] = ksm(fac[N],mod-2);
    for(int i = N-1;i >= 0;--i) inv[i] = inv[i+1]*(i+1)%mod;
}
inline int C(int m,int n){ return fac[m]*inv[m-n]%mod*inv[n]%mod; }
signed main(void){
    IOS;init();int t;for(cin >> t;t--;){
        int n, c, k, ans = 0;cin >> n >> c >> k;
        int tmp1 = ksm(691504013,c),tmp2 = ksm(308495997,c);
        int r1 = ksm(tmp1,k),r2 = 1;
        int rinv = ksm(tmp1,mod-2);
        for(int r = 0;r <= k;++r){
            int tt = r1*r2%mod,tmp;
            if(tt==1) tmp = n%mod;
            else tmp = tt*(ksm(tt,n)-1)%mod*ksm(tt-1,mod-2)%mod;
            tmp = tmp*C(k,r)%mod;
            if(r&1) ans -= tmp;
            else ans += tmp;
            r1 = r1 * rinv % mod;
            r2 = r2 * tmp2 % mod;
        }
        ans = (ans%mod+mod)%mod*ksm(276601605,k)%mod;
        cout << ans << endl;
    }
    return 0;
}
