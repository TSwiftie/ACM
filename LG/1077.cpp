/************************************************************
	> File Name: 1077.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 07 May 2020 01:54:20 PM CST
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
const int N = 105;
const int mod = 1e6+7;
int a[N];
int dp[N];
signed main(void){
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",a+i);
	dp[0] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 0;j--)
			for(int k = 1;k <= min(a[i],j);k++)
				dp[j] = (dp[j] + dp[j-k])%mod;
	printf("%d\n",dp[m]);
	return 0;
}
