/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 01 May 2020 10:17:28 AM CST
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
const LL mod = 1e9+7;
LL ksm(LL a,LL b){
	LL res = 1;
	while(b){
		if(b&1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		LL n, m;
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",m*ksm(2,n-1)%mod);
	}
	return 0;
}
