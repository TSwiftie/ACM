/************************************************************
	> File Name: 996B.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 07:51:08 PM CST
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
LL mod;
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
		scanf("%lld",&mod);
		int n;
		scanf("%d",&n);
		LL ans = 0;
		for(int i = 1;i <= n;i++){
			LL a, b;
			scanf("%lld%lld",&a,&b);
			ans = (ans + ksm(a,b)) % mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
