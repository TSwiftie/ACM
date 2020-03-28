/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 28 Mar 2020 10:04:40 AM CST
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
const int N = 1e3+5;
const int mod = 998244353;
ll x[N],y[N];
ll dis[N];
ll getDis(int i,int j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
signed main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lld%lld",x+i,y+i);
	ll ans = 0;
	for(int i = 1;i < n;i++)
		for(int j = i+1;j <= n;j++){
			ll Dis = getDis(i,j);
			ans = (ans + Dis*(n-2))%mod;
		}
	printf("%lld\n",ans);
	return 0;
}
