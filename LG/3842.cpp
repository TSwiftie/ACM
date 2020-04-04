/************************************************************
	> File Name: 3842.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 04:09:41 PM CST
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
const int N = 20005;
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int n,ls[N],rs[N],dp[2][2],l[N];
signed main(void){
	n = read()-1;
	for(int i = 0;i <= n;i++)
		ls[i] = read(),rs[i] = read(),l[i] = rs[i]-ls[i];
	dp[0][0] = rs[0]+l[0];
	dp[0][1] = ls[0]+l[0];
	for(int i = 1;i <= n;i++){
		dp[i%2][0] = min(dp[(i+1)%2][0]+abs(ls[i-1]-rs[i]),dp[(i+1)%2][1]+abs(rs[i-1]-rs[i]))+l[i]+1;
		dp[i%2][1] = min(dp[(i+1)%2][0]+abs(ls[i-1]-ls[i]),dp[(i+1)%2][1]+abs(rs[i-1]-ls[i]))+l[i]+1;
	}
	printf("%d\n",min(dp[n%2][0]-ls[n],dp[n%2][1]-rs[n])+n);
	return 0;
}
