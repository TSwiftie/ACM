/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 13 Apr 2020 08:31:31 AM CST
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
const int N = 1e5+10;
ll a[N];
bool cmp(ll a,ll b){
	return a > b;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		ll x;
		scanf("%d %lld",&n,&x);
		for(int i = 0;i < n;i++) scanf("%lld",a+i);
		sort(a,a+n,cmp);
		ll sum = 0,cnt = 0;
		while(cnt < n && sum + a[cnt] >= (cnt+1)*x){
			sum += a[cnt];
			cnt++;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
