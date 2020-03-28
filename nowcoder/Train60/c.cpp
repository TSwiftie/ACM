/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 28 Mar 2020 10:19:50 AM CST
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
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	ll d = a;
	if(b){
		d = exgcd(b,a%b,y,x);
		y -= (a/b)*x;
	}else x = 1,y = 0;
	return d;
}
int a, b, c;
ll k, x, y;
ll u, v;
ll resx,resy,resz;
bool solve(int a,int b,int c,ll k){
	ll d = gcd(a,b);
	ll g = exgcd(d,c,x,y);
	x *= k/g,y *= k/g;
	u = c/g,v = d/g;
	y += (-y/v)*v;
	while(y < 0) y += v;
	resz = y;
	k -= c*y;
	d = exgcd(a,b,x,y);
	x *= k/d,y *= k/d;
	u = b/d,v = a/d;
	ll coe = -y/v;
	y += coe*v;
	x -= coe*u;
	while(y < 0) y += v,x -= u;
	resx = x,resy = y;
	if(resx >= 0 && resy >= 0 && resz >= 0) return true;
	return false;
}
signed main(void){
	scanf("%d %d %d %lld",&a,&b,&c,&k);
	if(solve(a,b,c,k)){
		printf("%lld %lld %lld\n",resx,resy,resz);
		return 0;
	}
	if(solve(a,c,b,k)){
		printf("%lld %lld %lld\n",resx,resy,resz);
		return 0;
	}
	if(solve(b,c,a,k)){
		printf("%lld %lld %lld\n",resx,resy,resz);
		return 0;
	}
	return 0;
}
