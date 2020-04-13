/************************************************************
	> File Name: 4816.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 13 Apr 2020 04:09:08 PM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const ll mod = 1e9+7;
const int N = 1e6;
ll mu[N+10],f[N+10],F[N+10],g[N+10];
int prime[N>>3],n,m,t;
bool vis[N+10];
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	for(;ch<'0'||ch>'9';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline ll ksm(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = a * res % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
inline ll solve(int a,int b){
	if(a > b) a^=b, b=a^b,a^=b;
	ll res = 1,inv = 0;
	for(int l = 1,r;l <= a;l = r+1){
		r = min(a/(a/l),b/(b/l));
		inv = 1ll*F[r]*ksm(F[l-1],mod-2)%mod;
		(res*=ksm(inv,1ll*(a/l)*(b/l)%(mod-1)))%=mod;
	}
	return res;
}
signed main(void){
	mu[1] = f[1] = 1;g[1] = F[0] = F[1] = 1;
	for(int i = 2;i <= N;i++){
		f[i] = (f[i-1]+f[i-2])%mod;
		g[i] = ksm(f[i],mod-2);
		F[i] = 1;
		if(!vis[i]){
			prime[++m] = i;
			mu[i] = -1;
		}
		for(int j = 1;j <= m&&i*prime[j]<=N;j++){
			vis[i*prime[j]] = true;
			if(i%prime[j]==0) break;
			mu[prime[j]*i] = -mu[i];
		}
	}
	for(int i = 1;i <= N;i++){
		if(mu[i]==0) continue;
		for(int j = i;j <= N;j+=i)
			F[j] = 1ll*F[j]*(mu[i]==1?f[j/i]:g[j/i])%mod;
	}
	for(int i = 2;i <= N;i++) F[i] = 1ll*F[i]*F[i-1]%mod;
	for(t = read();t--;){
		n = read();
		m = read();
		printf("%lld\n",solve(n,m));
	}
	return 0;
}
