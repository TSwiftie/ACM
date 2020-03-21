/************************************************************
	> File Name: TreeChainDivide.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 21 Mar 2020 11:54:44 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
vi G[MAXN];
int fa[MAXN],dep[MAXN],son[MAXN],siz[MAXN],rnk[MAXN],dfn[MAXN],top[MAXN],idx;
void dfs1(int u,int f){
	fa[u] = f;dep[u] = dep[f]+1;siz[u] = 1;son[u] = -1;
	for(int v : G[u]) if(v^f){
		dfs1(v,u);
		siz[u] += siz[v];
		if(son[u]==-1||siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs2(int u,int t){
	top[u] = t;
	dfn[u] = ++idx;
	rnk[idx] = u;
	if(son[u]==-1) return ;
	dfs2(son[u],t);
	for(int v : G[u]) if(v^fa[u]&&v^son[u])
		dfs2(v,v);
}
signed main(void){
	return 0;
}
