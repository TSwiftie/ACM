/************************************************************
	> File Name: 5414.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 03:36:21 PM CST
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
const int N = 104;
int dp[N],a[N],sum;
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		sum = 0;
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i),sum += a[i];
		for(int i = 1;i <= n;i++){
			for(int j = 1;j < i;j++)
				if(a[j] <= a[i])
					dp[i] = max(dp[i],dp[j]);
			dp[i] += a[i];
		}
		int maxx = 0;
		for(int i = 1;i <= n;i++)
			maxx = max(maxx,dp[i]);
		printf("%d\n",sum-maxx);
		memset(dp,0,sizeof dp);
	}
	return 0;
}
