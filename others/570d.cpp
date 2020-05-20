/************************************************************
	> File Name: 570d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 04:47:38 PM CST
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
const int N = 5e5+10;
int n, m;
int siz[N],w[N],son[N],d[N],cnt[N][30],ans[N];
bool vis[N];
vector<pii> Q[N];
vi G[N];
void dfs(int u,int f){
	d[u] = d[f]+1;
	siz[u] = 1;
	for(int v : G[u]) if(v!=f){
		dfs(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void calc(int u,int val){
	cnt[d[u]][w[u]] += val;
	for(int v : G[u]) if(!vis[v])
		calc(v,val);
}
void dsu(int u,bool keep){
	for(int v : G[u]) if(v!=son[u])
		dsu(v,0);
	if(son[u]) dsu(son[u],1),vis[son[u]] = true;
	calc(u,1);
	for(int i = 0,t,id,dep;i < SZ(Q[u]);i++){
		id = Q[u][i].first,dep = Q[u][i].second,t = 0;
		for(int j = 0;j < 26;j++)
			if(cnt[dep][j]&1) t++;
		ans[id] = t>1 ? 0 : 1;
	}
	if(son[u]) vis[son[u]] = false;
	if(!keep) calc(u,-1);
}
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 2,f;i <= n;i++)
		scanf("%d",&f),G[f].push_back(i);
	char ch;
	for(int i = 1;i <= n;i++) 
		cin >> ch,w[i] = ch-'a';
	dfs(1,0);
	for(int i = 1,u,v;i <= m;i++)
		scanf("%d%d",&u,&v),Q[u].push_back(make_pair(i,v));
	dsu(1,0);
	for(int i = 1;i <= m;i++){
		if(ans[i]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
