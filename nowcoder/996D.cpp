/************************************************************
	> File Name: 996D.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 07:55:19 PM CST
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
int dp[1<<20][20];
int n, G[20][20];
signed main(void){
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d",&G[i][j]);
	memset(dp,0x3f,sizeof dp);
	dp[1][0] = 0;
	for(int i = 1;i < 1<<n;i++)
		for(int j = 0;j < n;j++)
			if(i>>j&1)
				for(int k = 0;k < n;k++)
					if((i^1<<j)>>k&1)
						dp[i][j] = min(dp[i][j],dp[i^1<<j][k]+G[k][j]);
	printf("%d\n",dp[(1<<n)-1][n-1]);
	return 0;
}
