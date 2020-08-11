/************************************************************
	> File Name: 6827.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 11 Aug 2020 11:09:19 AM CST
************************************************************/
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
const int p = 1e9+7;
const int N = 2e5+10;
int T,n,a[N],inv[N],sinv[N],ans,C;
inline int ksm(int a,int b,int res = 1){ for(a%=p;b;a = a * a % p,b >>= 1) if(b&1) res = res * a % p; return res; }
inline void init(int n){
    inv[1] = 1;
    for(int i = 2;i <= n;++i) inv[i] = (p-p/i)*inv[p%i]%p;
    for(int i = 1;i <= n;++i) sinv[i] = (sinv[i-1] + inv[i]) % p;
}
inline void solve(){
    scanf("%lld",&n);C = ans = 0;
    for(int i = 1;i <= n;++i) scanf("%lld",a+i);
    for(int i = 1,q = n>>1;i <= q;++i){
        int cov = i;
        cov+=i*(sinv[n-i]-sinv[i]+p)%p;cov%=p;
        (C+=i*inv[n-i+1]%p)%=p;(cov+=C)%=p;
        (ans+=a[i]*cov%p)%=p;(ans+=a[n+1-i]*cov%p)%=p;
    }
    if(n&1){
        int cov = 0;
        for(int i = 1;i <= n;++i) (cov+=min(i,n+1-i)*inv[i]%p)%=p;
        (ans+=cov*a[(n>>1)+1]%p)%=p;
    }
    printf("%lld\n",ans*ksm(1ll*n*(n+1)/2,p-2)%p);
}
signed main(void){
    init(200000);
    for(scanf("%lld",&T);T--;) solve();
    return 0;
}
