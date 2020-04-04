/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 06:55:15 PM CST
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
const int N = 102;
int a[N];
signed main(void){
	int t, n, d;
	for(scanf("%d",&t);t--;){
		scanf("%d %d",&n,&d);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		int ans = a[1];
		for(int i = 2;i <= n;i++){
			if(!a[i]) continue;
			if(d/(i-1) <= 0) break;
			ans += min(d/(i-1),a[i]);
			d -= min(d/(i-1),a[i])*(i-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
