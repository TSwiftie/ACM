/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 16 Mar 2020 04:31:59 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
signed main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		ll x, y;
		scanf("%lld %lld",&x,&y);
		ll l = 0,r = min(x/2,y/3);
		while(r-l>10){
			ll m1 = l+(r-l)/3,m2 = r-(r-l)/3;
			if(m1+min((x-2*m1)/4,y-3*m1)>m2+min((x-2*m2)/4,y-3*m2)) r = m2;
			else l = m1;
		}
		ll ans = 0;
		for(int i = l;i <= r;i++)
			ans = max(ans,i+min((x-2*i)/4,y-3*i));
		printf("%lld\n",ans);
	}
	return 0;
}
