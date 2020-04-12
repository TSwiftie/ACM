/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 12 Apr 2020 10:27:01 PM CST
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
int n;
ll a[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		int ans = 0;
		scanf("%lld",a+1);
		ll Max = a[1],res = -INF;
		for(int i = 2;i <= n;i++){
			scanf("%lld",a+i);
			res = max(res,Max-a[i]);
			Max = max(Max,a[i]);
		}
		ll st = 0;
		while(st < res){
			st = st<<1|1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
