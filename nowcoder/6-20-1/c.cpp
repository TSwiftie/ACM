/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 22 Jun 2020 10:36:53 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
mt19937 rnd(time(0));
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
const int N = 1e2+10;
int dp[N];
signed main(void){
	IOS;
	int n,x;
	dp[1] = 1;dp[2] = 2;dp[3] = 4;
	for(int i = 4;i <= 100;++i)
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	for(cin >> n;n--;){
		cin >> x;
		cout << dp[x] << endl;
	}
	return 0;
}
