/************************************************************
	> File Name: 3868.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 02:25:48 PM CST
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
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int k;
ll a[20],b[20];
ll qmul(ll a,ll b,ll mod){
	ll ans = 0;
	while(b){
		if(b&1) ans = (ans + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return ans;
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x = 1;y = 0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
ll CRT(){
	ll ans = 0,lcm = 1,x,y;
	for(int i = 1;i <= k;i++) lcm*=b[i];
	for(int i = 1;i <= k;i++){
		ll tp = lcm/b[i];
		exgcd(tp,b[i],x,y);
		x = (x % b[i] + b[i]) % b[i];
		ans = (ans + qmul(qmul(tp,x,lcm),a[i],lcm))%lcm;
	}
	return (ans + lcm)%lcm;
}
signed main(void){
	k = read();
	for(int i = 1;i <= k;i++) a[i] = read();
	for(int i = 1;i <= k;i++) b[i] = read();
	for(int i = 1;i <= k;i++) a[i] = (a[i]%b[i]+b[i])%b[i];
	printf("%lld\n",CRT());
	return 0;
}
