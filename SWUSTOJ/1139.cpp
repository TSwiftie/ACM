/************************************************************
	> File Name: 1139.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 13 May 2020 05:35:11 PM CST
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
const int N = 1e4+10;
int n;
LL a[N],dp[N];
signed main(void){
	scanf("%d",&n);
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%lld",a+i);
		dp[i] = max(dp[i-1],dp[i-2]+a[i]);
	}
	printf("%lld\n",dp[n]);
	return 0;
}
