/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 05 Apr 2020 03:05:35 PM CST
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
const ll mod = 998244353;
const int N = 1e5+10;
ll sum[N];
signed main(void){
	ll st = 2;
	while(st < N){
		sum[st] = st;
		st <<= 1;
	}
	for(int i = 1;i < N;i++){
		if(sum[i]) continue;
		sum[i] = i&1?1:2;
	}
	for(int i = 1;i < N;i++)
		sum[i] = (sum[i-1] + sum[i]) % mod;
	ll n,ans = 0;
	scanf("%lld",&n);
	for(ll l = 1,r;l <= n;l = r+1){
		r = n/(n/l);
		ans = (ans + (sum[r]-sum[l-1]+mod)%mod*(n/l)%mod)%mod;
	}
	printf("%lld\n",ans);
}
