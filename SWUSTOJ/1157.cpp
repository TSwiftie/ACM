/************************************************************
	> File Name: 1157.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 27 Mar 2020 11:14:14 AM CST
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
ll lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}
signed main(void){
	ll n;
	while(~scanf("%lld",&n)){
		ll _lcm = 1;
		for(ll i = 1,x;i <= n;i++){
			scanf("%lld",&x);
			_lcm = lcm(_lcm,x);
		}
		printf("%lld\n",_lcm);
	}
	return 0;
}
