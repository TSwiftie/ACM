/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 05 Jun 2020 11:20:29 AM CST
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
ll f(ll n){
	if(n==1) return 1;
	else return f(n/2) + n;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",f(n));
	}
	return 0;
}
