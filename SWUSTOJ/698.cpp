/************************************************************
	> File Name: 698.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 25 Mar 2020 11:14:10 PM CST
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
int dp[205][100006],a[205],b[205];
signed main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1;i <= n;i++) scanf("%d",b+i);
	int Sum = 0;
	for(int i = 1;i <= n;i++){
		Sum += a[i];
		for(int j = 0;j <= Sum;j++){
			dp[i][j] = dp[i-1][j] + b[i];
			if(j >= a[i]) dp[i][j] = min(dp[i-1][j]+b[i],dp[i-1][j-a[i]]);
		}
	}
	int ans = INF;
	for(int i = 0;i <= Sum;i++) ans = min(ans,max(dp[n][i],i));
	printf("%d\n",ans);
	return 0;
}
