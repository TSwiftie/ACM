/************************************************************
	> File Name: 2016.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 12 May 2020 08:19:45 PM CST
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
const int N = 1510;
vi G[N];
int n;
int dp[N][2],ans[N];
void dfs(int u,int f){
	dp[u][0] = 0;dp[u][1] = 1;
	for(int v : G[u]) if(v!=f){
		dfs(v,u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1],dp[v][0]);
	}
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1,u,v,k;i <= n;i++){
		scanf("%d",&u);
		scanf("%d",&k);
		while(k--){
			scanf("%d",&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
	dfs(0,-1);
	printf("%d\n",min(dp[0][0],dp[0][1]));
	return 0;
}
