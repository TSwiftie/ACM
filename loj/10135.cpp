/************************************************************
	> File Name: 10135.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 08:10:12 PM CST
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
const int N = 4e4+10;
vi G[N];
void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
int n, m;
int fa[N],siz[N],dep[N],son[N],top[N];
void dfs1(int u,int f){
	fa[u] = f,dep[u] = dep[f] + 1,siz[u] = 1;
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
		if(dep[top[u]] < dep[top[v]]) swap(u,v);
		u = fa[top[u]];
	}
	return dep[v] > dep[u] ? u : v;
}
signed main(void){
	scanf("%d",&n);
	int rt;
	for(int i = 1,a,b;i <= n;i++){
		scanf("%d%d",&a,&b);
		if(b==-1) rt = a;
		else add_edge(a,b);
	}
	dfs1(rt,0);
	dfs2(rt,rt);
	scanf("%d",&m);
	while(m--){
		int u, v;
		scanf("%d%d",&u,&v);
		int lca = LCA(u,v);
		if(lca==u) printf("1\n");
		else if(lca==v) printf("2\n");
		else printf("0\n");
	}
	return 0;
}
