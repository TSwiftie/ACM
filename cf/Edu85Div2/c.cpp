/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 13 Apr 2020 02:35:39 PM CST
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
const int N = 3e5+10;
ll a[N],b[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			scanf("%lld%lld",a+i,b+i);
		ll ans = 0,mn = 1e18;
		for(int i = 0;i < n;i++){
			int ni = (i+1)%n;
			ll val = min(a[ni],b[i]);
			ans += a[ni]-val;
			mn = min(mn,val);
		}
		ans += mn;
		printf("%lld\n",ans);
	}
	return 0;
}
