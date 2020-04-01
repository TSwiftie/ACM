/************************************************************
	> File Name: 3884.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 03:24:11 PM CST
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
const int N = 103;
vi G[N];
int n,depth = 0,width = 0;
int fa[N],dep[N],siz[N],son[N],top[N];
void dfs1(int u,int f){
	fa[u] = f;dep[u] = dep[f]+1;siz[u] = 1;
	depth = max(depth,dep[u]);
	for(int v : G[u]) if(v!=f){
		dfs1(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	if(son[u]) dfs2(son[u],t);
	for(int v : G[u]) if(v!=fa[u]&&v!=son[u])
		dfs2(v,v);
}
int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[v]] > dep[top[u]])
			swap(u,v);
		u = fa[top[u]];
	}
	return dep[v] > dep[u] ? u : v;
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int u, v;
	scanf("%d%d",&u,&v);
	dfs1(1,0);
	dfs2(1,1);
	int lca = LCA(u,v);
	int ans = (dep[u]-dep[lca])*2+dep[v]-dep[lca];
	queue<int>q;
	q.push(1);
	while(q.size()){
		int num = q.size();
		width = max(width,num);
		while(num--){
			int u = q.front();
			q.pop();
			for(int v : G[u]) if(v!=fa[u])
				q.push(v);
		}
	}
	printf("%d\n%d\n%d\n",depth,width,ans);
	return 0;
}
