/************************************************************
	> File Name: 2480.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 10 Apr 2020 10:09:25 AM CST
************************************************************/

#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
ll phi(ll n){
	ll ans = n;
	for(ll i = 2;i*i <= n;i++)
		if(n%i==0){
			ans = ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	if(n > 1) ans = ans/n*(n-1);
	return ans;
}
signed main(void){
	ll n,ans;
	while(~scanf("%lld",&n)){
		ans = 0;
		for(ll i = 1;i*i <= n;i++){
			if(n%i==0){
				ans += phi(n/i)*i;
				if(i*i!=n)
					ans += phi(i)*(n/i);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
