/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 01:24:43 PM CST
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
int t,nr,ng,nb;
ll ans;
ll sq(int x){
	return 1ll*x*x;
}
void solve(vi a,vi b,vi c){
	for(int x : a){
		auto y = lower_bound(all(b),x);
		auto z = upper_bound(all(c),x);
		if(y==b.end()||z==c.begin()) continue;
		z--;
		ans = min(ans,sq(x-*y)+sq(*y-*z)+sq(*z-x));
	}
}
signed main(void){
	for(scanf("%d",&t);t--;){
		scanf("%d%d%d",&nr,&ng,&nb);
		vi r(nr),g(ng),b(nb);
		for(int i = 0;i < nr;i++) scanf("%d",&r[i]);
		for(int i = 0;i < ng;i++) scanf("%d",&g[i]);
		for(int i = 0;i < nb;i++) scanf("%d",&b[i]);
		sort(all(r));sort(all(g));sort(all(b));
		ans = 9e18;
		solve(r,g,b);solve(r,b,g);
		solve(g,b,r);solve(g,r,b);
		solve(b,r,g);solve(b,g,r);
		printf("%lld\n",ans);
	}
	return 0;
}
