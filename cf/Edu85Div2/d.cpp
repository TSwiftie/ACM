/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 01:44:57 PM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		ll n, l, r, base = 0;
		scanf("%lld%lld%lld",&n,&l,&r);
		for(ll i = (n-1)*2;i;base+=i,i-=2){
			for(ll j = max(base+1,l);j <= min(r,base+i);j++){
				if(j%2) printf("%lld ",n-i/2);
				else printf("%lld ",(j-base)/2+n-i/2);
			}
		}
		if(base==r-1) printf("1");
		puts("");
	}
	return 0;
}
