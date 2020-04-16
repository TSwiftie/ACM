/************************************************************
	> File Name: 3379.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 16 Apr 2020 09:20:41 PM CST
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
const int N = 500006;
int n, m, s;
vi G[N];
int fa[N],siz[N],dep[N],top[N],son[N];
void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void dfs1(int u,int f){
	fa[u] = f;dep[u] = dep[f]+1;siz[u] = 1;
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
int lca(int u,int v){
	while(top[u] != top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u,v);
		u = fa[top[u]];
	}
	return dep[u] > dep[v] ? v : u;
}
signed main(void){
	scanf("%d%d%d",&n,&m,&s);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs1(s,0);
	dfs2(s,s);
	while(m--){
		int u, v;
		scanf("%d%d",&u,&v);
		printf("%d\n",lca(u,v));
	}
	return 0;
}
