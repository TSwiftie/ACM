/************************************************************
	> File Name: 3146.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 07 May 2020 06:26:04 PM CST
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
typedef long long LL;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 255;
int n, dp[N][N], mp[N], ans;
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",mp+i);
	for(int i = 1;i <= n;i++)
		dp[i][i] = mp[i];
	for(int len = 2;len <= n;len++)
		for(int i = 1;i+len <= n+1;i++){
			int j = i+len-1;
			for(int k = i;k < j;k++)
				if(dp[i][k]==dp[k+1][j])
					dp[i][j] = max(dp[i][j],dp[i][k]+1);
			ans = max(ans,dp[i][j]);
		}
	printf("%d\n",ans);
	return 0;
}
