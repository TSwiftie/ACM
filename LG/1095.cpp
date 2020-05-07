/************************************************************
	> File Name: 1095.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 07 May 2020 01:45:13 PM CST
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
int dp[300001];
signed main(void){
	int m, s, t;
	scanf("%d%d%d",&m,&s,&t);
	for(int i = 1;i <= t;i++){
		if(m >= 10) dp[i] = dp[i-1]+60,m -= 10;
		else dp[i] = dp[i-1],m += 4;
	}
	for(int i = 1;i <= t;i++){
		dp[i] = max(dp[i],dp[i-1]+17);
		if(dp[i] >= s){
			printf("Yes\n%d\n",i);
			return 0;
		}
	}
	printf("No\n%d\n",dp[t]);
	return 0;
}
