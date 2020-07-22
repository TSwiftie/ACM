/************************************************************
	> File Name: 1005.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 07:20:20 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
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
const ll p = 1e9+9;
const int N = 1e5+10;
const ll a = 691504013;
const ll b = 308495997;
const ll d = 276601605;
const ll pmod = 1e9+8;
ll fac[N],inv[N],facA[N],facB[N];
inline ll read(){
    ll x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    return x * f;
}
inline ll ksm(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res%p;
}
inline ll C(ll n,ll m){
    return fac[n] * inv[m] % p * inv[n-m] % p;
}
signed main(void){
    int T;
    fac[0] = fac[1] = 1;inv[0] = inv[1] = 1;
    facA[0] = facB[0] = 1;
    facA[1] = a;facB[1] = b;
    for(int i = 2;i < N;++i){
        fac[i] = fac[i-1] * i % p;
        inv[i] = (p - p / i) * inv[p % i] % p;
        facA[i] = facA[i-1] * a % p;
        facB[i] = facB[i-1] * b % p;
    }
    for(int i = 1;i < N;++i) inv[i] = inv[i] * inv[i-1] % p;
    for(scanf("%d",&T);T--;){
        ll n, c, k, nn, cc;
        scanf("%lld%lld%lld",&n,&c,&k);
        ll res = ksm(d,k);
        ll tmp = 0;
        if(n < pmod) nn = n;
        else nn = n % pmod + pmod;
        if(c < pmod) cc = c;
        else cc = c % pmod + pmod;
        for(int i = 0;i <= k;++i){
            ll tt = ksm(facA[k-i]*facB[i]%p,cc);
            ll rem = tt==1 ? n%p : tt*(ksm(tt,nn)-1+p)%p*ksm(tt-1,p-2)%p;
            tt = rem * C(k,i) % p;
            if(~i&1) tmp = (tmp + tt) % p;
            else tmp = (tmp - tt + p) % p;
        }
        printf("%lld\n",res*tmp%p);
    }
    return 0;
}
