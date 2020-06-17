/************************************************************
	> File Name: 6264.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 10:53:15 AM CST
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
const int N = 2e5+10;
int n, m, p, dep;
vi G[N];
bool vis[N],mark;
void dfs(int u){
	if(vis[u]){
		mark = true;
		return ;
	}
	if(!SZ(G[u])) return ;
	++dep;
	vis[u] = true;
	for(int v : G[u])
		dfs(v);
}
signed main(void){
	scanf("%d%d%d",&n,&m,&p);
	for(int i = 1,a,b;i <= n;++i){
		scanf("%d%d",&a,&b);
		if(!G[b].size()) G[b].push_back(a);
	}
	dfs(p);
	if(mark) printf("-1\n");
	else printf("%d\n",dep);
	return 0;
}
