/************************************************************
	> File Name: 450.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 25 Mar 2020 10:29:25 PM CST
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
const int N = 303;
int n, m, rt;
int pre[N],val[N],wei[N];
vi G[N];
int dp[N][N];
void dfs(int u){
	for(int i = 1;i <= m;i++) dp[u][i] = val[u];
	for(int i = 0;i < SZ(G[u]);i++){
		int v = G[u][i];
		dfs(v);
		for(int j = m;j >= 1;j--)
			for(int k = 1;k <= (u==rt?j:j-1);k++)
				dp[u][j] = max(dp[u][j],dp[u][j-k]+dp[v][k]);
	}
}
signed main(void){
	while(~scanf("%d%d",&n,&m)){
		for(int i = 0;i <= n;i++) G[i].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d%d",pre+i,val+i);
			if(pre[i]) G[pre[i]].push_back(i);
		}
		rt = 0;
		for(int i = 1;i <= n;i++)
			if(!pre[i]) G[rt].push_back(i);
		val[rt] = 0;
		dfs(rt);
		printf("%d\n",dp[rt][m]);
	}
	return 0;
}
