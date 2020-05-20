/************************************************************
	> File Name: 10130.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 08:25:31 PM CST
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
vi G[N];
void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
int n, m;
int fa[N],siz[N],dep[N],son[N],top[N],dfn[N],rnk[N],idx;
void dfs1(int u,int f){
	dep[u] = dep[f] + 1;
	fa[u] = f;
	siz[u] = 1;
	for(int v : G[u]) if(v!=f){
		dfs1(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	dfn[u] = ++idx;
	rnk[idx] = u;
	if(son[u]) dfs2(son[u],t);
	for(int v : G[u]) if(v!=fa[u] && v!=son[u])
		dfs2(v,v);
}
struct SegTree{
	int tr[N<<2];
	void build(int o,int L,int R){
		if(L==R){
			tr[o] = 1;
			return ;
		}
		int mid = (L+R)>>1;
		build(lc,L,mid);
		build(rc,mid+1,R);
		tr[o] = tr[lc] + tr[rc];
	}
	int query(int o,int L,int R,int l,int r){
		if(R < l || r < L) return 0;
		if(l <= L && R <= r) return tr[o];
		int mid = (L+R)>>1;
		return query(lc,L,mid,l,r)+query(rc,mid+1,R,l,r);
	}
}seg;
int querySum(int u,int v){
	int ans = -1;
	while(top[u]!=top[v]){
		if(dep[top[u]] < dep[top[v]]) swap(u,v);
		ans += seg.query(1,1,n,dfn[top[u]],dfn[u]);
		u = fa[top[u]];
	}
	if(dep[v] > dep[u]) swap(u,v);
	ans += seg.query(1,1,n,dfn[v],dfn[u]);
	return ans;
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	seg.build(1,1,n);
	dfs1(1,0);
	dfs2(1,1);
	scanf("%d",&m);
	while(m--){
		int u, v;
		scanf("%d%d",&u,&v);
		printf("%d\n",querySum(u,v));
	}
	return 0;
}
