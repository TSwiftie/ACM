/************************************************************
	> File Name: 2513.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 06 May 2020 12:17:14 PM CST
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
int n, k, p = 10000, dp[1010][1010];
signed main(void){
	scanf("%d%d",&n,&k);
	dp[1][0] = 1;
	for(int i = 2;i <= n;i++){
		int sum = 0;
		for(int j = 0;j <= k;j++){
			sum = (sum + dp[i-1][j])%p;
			dp[i][j] = sum;
			if(j >= i-1)
				sum = (sum - dp[i-1][j-i+1] + p) % p;
		}
	}
	printf("%d\n",dp[n][k]);
	return 0;
}
