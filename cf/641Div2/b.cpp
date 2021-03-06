/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 05:31:05 PM CST
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
const int N = 1e5+10;
int s[N],n,dp[N];
signed main(void){
	IOS;
	int t;
	for(cin >> t;t--;){
		cin >> n;
		for(int i = 1;i <= n;i++)
			cin >> s[i],dp[i] = 1;
		for(int i = 1;i <= n;i++)
			for(int j = 2*i;j <= n;j += i)
				if(s[j] > s[i]) dp[j] = max(dp[j],dp[i]+1);
		int ans = 0;
		for(int i = 1;i <= n;i++) ans = max(ans,dp[i]);
		cout << ans << endl;
	}
	return 0;
}
