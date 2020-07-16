/************************************************************
	> File Name: j.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 11时02分23秒
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
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 2e6+10;
const int mod = 998244353;
int fac[N],inv[N];
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
signed main(void){
    IOS;
    fac[0] = 1;
    for(int i = 1;i <= N-1;++i) fac[i] = fac[i-1] * i % mod;
    inv[N-1] = ksm(fac[N-1],mod-2);
    for(int i = N-1;i >= 1;i--) inv[i-1] = inv[i]*i%mod;
    int n;
    while(cin >> n){
        int ans = fac[2*n+1]*(inv[n]*inv[n]%mod)%mod;
        printf("%lld\n",ksm(ans,mod-2));
    }
}
