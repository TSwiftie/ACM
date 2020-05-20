/************************************************************
	> File Name: 5318.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 07:29:39 PM CST
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
set<int>G[N];
int n, m;
bool vis[N];
void dfs(int u,int f){
	vis[u] = true;
	cout << u << " ";
	for(int v : G[u]) if(v!=f&&!vis[v])
		dfs(v,u);
}
void bfs(){
	memset(vis,false,sizeof vis);
	queue<int>q;
	q.push(1);
	vis[1] = true;
	while(q.size()){
		int u = q.front();
		q.pop();
		cout << u << " ";
		for(int v : G[u])
			if(!vis[v]){
				vis[v] = true; 
				q.push(v);
			}
	}
}
signed main(void){
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i <= m;i++){
		scanf("%d%d",&u,&v);
		G[u].insert(v);
		G[v].insert(u);
	}
	dfs(1,0);
	cout << endl;
	bfs();
	return 0;
}
