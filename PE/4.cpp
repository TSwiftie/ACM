/************************************************************
	> File Name: 4.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 28 Mar 2020 01:32:30 PM CST
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
ll a[100],cnt;
bool judge(ll x){
	cnt = 0;
	while(x){
		a[++cnt] = x%10;
		x /= 10;
	}
	int st = 1,ed = cnt;
	while(st < ed){
		if(a[st]!=a[ed]) return false;
		st++;
		ed--;
	}
	return true;
}
signed main(void){
	ll ans = 0;
	for(ll i = 100;i <= 999;i++)
		for(ll j = i+1;j <= 999;j++){
			ll now = i*j;
			if(judge(now)) ans = max(ans,now);
		}
	printf("%lld\n",ans);
	return 0;
}
