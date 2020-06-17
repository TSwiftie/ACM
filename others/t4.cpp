/************************************************************
	> File Name: te4.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 07:26:30 PM CST
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
int n, m;
int blIdx[N];
vector<int>G[N];
vector<pair<int,int>>del,add;
int block[N],scc,dfn[N],idx;
void dfs(int u,int f){
	block[u] = scc;
	dfn[u] = ++idx;
	for(int v : G[u]) if(v!=f){
		if(!dfn[v]) dfs(v,u);
		else if(dfn[v] < dfn[u]) del.push_back(make_pair(u,v));
	}
}
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i <= m;++i){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(m < n-1){
		printf("-1\n");
		return 0;
	}
	for(int i = 1;i <= n;++i){
		if(!dfn[i]){
			blIdx[++scc] = i;
			idx = 1;
			dfs(i,0);
		}
	}
	if(SZ(del) >= scc-1){
		printf("%d\n",scc-1);
		for(int i = 2;i <= scc;++i)
			add.push_back(make_pair(blIdx[1],blIdx[i]));
		for(int i = 0;i < scc-1;++i){
			printf("%d %d %d %d\n",del[i].first,del[i].second,add[i].first,add[i].second);
		}
	}else printf("-1\n");
	return 0;
}
