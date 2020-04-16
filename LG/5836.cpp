/************************************************************
	> File Name: 5836.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 16 Apr 2020 08:19:07 PM CST
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
const int N = 100005;
int n, m, h[N];
vi E[N];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}
char s[N];
int H[N],G[N],f[N][20],t,d[N];
void dfs(int u,int fa){
	d[u] = d[fa]+1;f[u][0] = fa;
	if(s[u]=='H') H[u] = 1;
	else G[u] = 1;
	H[u] += H[fa];G[u] += G[fa];
	for(int i = 1;i <= t;i++) f[u][i] = f[f[u][i-1]][i-1];
	for(int v : E[u]) if(v!=fa)
		dfs(v,u);
}
int lca(int u,int v){
	if(d[u] < d[v]) swap(u,v);
	for(int i = t;i >= 0;i--) if(d[f[u][i]] >= d[v]) u = f[u][i];
	if(u==v) return u;
	for(int i = t;i >= 0;i--) if(f[u][i]!=f[v][i]) u = f[u][i],v = f[v][i];
	return f[u][0];
}
signed main(void){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	t = log2(n);
	dfs(1,0);
	int u, v;
	char op[2];
	while(m--){
		scanf("%d%d%s",&u,&v,op);
		int val,LCA = lca(u,v);
		if(op[0]=='H') val = H[u]+H[v]-H[LCA]-H[f[LCA][0]];
		else val = G[u]+G[v]-G[LCA]-G[f[LCA][0]];
		if(val) putchar('1');
		else putchar('0');
	}
	puts("");
	return 0;
}
