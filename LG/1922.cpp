/************************************************************
	> File Name: 1922.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 25 Apr 2020 11:23:26 AM CST
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
const int N = 1e5+5;
int n,in[N],ans[N];
vi G[N];
void dfs(int u,int f){
	int sum = 1;
	for(int v : G[u]) if(v!=f){
		dfs(v,u);
		if(in[v]==1) sum++;
		else ans[u] += ans[v];
	}
	ans[u] += sum/2;
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i < n;i++){
		int u, v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		in[u]++,in[v]++;
	}
	dfs(1,0);
	printf("%d\n",ans[1]);
	return 0;
}
