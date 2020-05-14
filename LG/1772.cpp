/************************************************************
	> File Name: 1772.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 14 May 2020 10:44:45 AM CST
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
const int N = 1e2+5;
int n, m, K, e, d;
int ocrd[N][N];
int used[N];
int dp[N];
struct Edge{
	int u,v,w,next;
}edge[N<<2];
int head[N],tot;
void add_edge(int u,int v,int w){
	edge[++tot].u = u;
	edge[tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot;
}
int dis[N];
bool vis[N];
int dijkstra(){
	priority_queue<pii>q;
	memset(dis,INF,sizeof dis);
	memset(vis,false,sizeof vis);
	dis[1] = 0;
	q.push({-dis[1],1});
	while(q.size()){
		int u = q.top().second;
		q.pop();
		if(vis[u]||used[u]) continue;
		vis[u] = true;
		for(int i = head[u];i;i = edge[i].next){
			int v = edge[i].v;
			if(vis[v]||used[v]) continue;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				q.push({-dis[v],v});
			}
		}
	}
	return dis[m];
}
signed main(void){
	IOS;
	cin >> n >> m >> K >> e;
	for(int i = 1,u,v,w;i <= e;i++){
		cin >> u >> v >> w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	cin >> d;
	for(int i = 1;i <= d;i++){
		int p, st, ed;
		cin >> p >> st >> ed;
		for(int j = st;j <= ed;j++)
			ocrd[p][j] = 1;
	}
	memset(dp,INF,sizeof dp);
	dp[0] = 0;
	for(int i = 1;i <= n;i++){
		memset(used,0,sizeof used);
		for(int j = i;j ;j--){
			for(int k = 1;k <= m;k++)
				used[k] |= ocrd[k][j];
			int dist = dijkstra();
			if(dist >= INF) break;
			dp[i] = min(dp[i],dp[j-1]+(i-j+1)*dist+K);
		}
	}
	cout << dp[n] - K << endl;
	return 0;
}
