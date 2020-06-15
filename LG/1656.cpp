/************************************************************
	> File Name: 1656.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 15 Jun 2020 11:03:08 AM CST
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
const int N = 201;
const int M = 1e4+10;
int n, m;
int e[N][N];
struct Edge{
	int u,v;
}edge[M];
bool vis[N];
void dfs(int u,int f){
	vis[u] = true;
	for(int i = 1;i <= n;++i){
		if(u==i) continue;
		if(e[u][i]&&!vis[i]&&i!=f)
			dfs(i,u);
	}
}
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i <= m;++i){
		scanf("%d%d",&u,&v);
		++e[u][v];
		++e[v][u];
		edge[i].u = u;
		edge[i].v = v;
	}
	vector<pii>ans;
	for(int i = 1;i <= m;++i){
		int u = edge[i].u,v = edge[i].v;
		--e[u][v];
		--e[v][u];
		dfs(1,0);
		for(int j = 1;j <= n;++j)
			if(!vis[j]){
				ans.push_back(make_pair(min(u,v),max(u,v)));
				break;
			}
		memset(vis,false,sizeof vis);
		++e[u][v];
		++e[v][u];
	}
	sort(all(ans));
	for(pii i : ans)
		printf("%d %d\n",i.first,i.second);
	return 0;
}
