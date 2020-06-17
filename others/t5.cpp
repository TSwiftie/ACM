/************************************************************
	> File Name: t5.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 07:09:06 PM CST
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
typedef long long ll;
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
const int p = 1e9+7;
const int N = 1e5+10;
int dp[N][2];
signed main(void){
	int q, k;
	cin >> q >> k;
	dp[1][0] = 1,dp[1][1] = 1==k;
	for(int i = 1;i <= 1e5;++i){
		dp[i+k][1] = (dp[i+k][1] + dp[i][0]) % p;
		dp[i+1][0] = (dp[i+1][0] + dp[i][0]) % p;
		dp[i+1][0] = (dp[i+1][0] + dp[i][1]) % p;
	}
	for(int i = 1;i <= 10;++i)
		cout << dp[i][0] + dp[i][1] << endl;
	while(q--){
		int l, r;
		cin >> l >> r;
		cout << ((dp[r][0]+dp[r][1]) % p - (dp[l-1][0]+dp[l-1][1])%p + p) % p << endl;
	}
	return 0;
}
