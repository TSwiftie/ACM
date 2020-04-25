/************************************************************
	> File Name: 1754.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 25 Apr 2020 10:55:14 AM CST
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
ll n, dp[100][100];
signed main(void){
	cin >> n;
	for(int i = 1;i <= n;i++)
		dp[i][0] = 1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= i;j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	cout << dp[n][n] << endl;
	return 0;
}
