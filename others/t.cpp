/************************************************************
	> File Name: t.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 08:41:38 PM CST
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
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int a[3003][3003];
int dp[3003][3003];
signed main(void){
	int n = read(),m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			a[i][j] = read();
	dp[n][m] = 1;
	for(int i = n;i >= 1;i--)
		for(int j = m;j >= 1;j--){
			if(a[i][j]==1) continue;
			dp[i][j] = (dp[i][j]+dp[i+1][j]+dp[i][j+1])%2333;
		}
	printf("%d\n",dp[1][1]);
	return 0;
}
