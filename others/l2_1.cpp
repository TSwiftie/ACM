#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EXP = 1e-8;
struct Edge{
	int v,w,next;
}edge[MAXM];
int head[MAXN],tot;
void add_edge(int u,int v,int w){
	edge[++tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot;
}
int path[MAXN],c[MAXN],pre[MAXN],ans[MAXN];
int dis[MAXN];
bool vis[MAXN];
int n,m,S,D;
void Dijkstra(){
	for(int i = 0;i < n;i++)
		dis[i] = INF,vis[i] = false;
	dis[S] = 0;
	ans[S] = c[S];
	priority_queue<pii>q;
	q.push({-dis[S],S});
    pre[S] = S;
	path[S] = 1;
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i = head[u];i;i = edge[i].next){
			int v = edge[i].v;
			if(dis[v] > dis[u] + edge[i].w){
				path[v] = path[u];
				dis[v] = dis[u] + edge[i].w;
				ans[v] = ans[u] + c[v];
				pre[v] = u;
				q.push({-dis[v],v});
			}else if(dis[v]==dis[u]+edge[i].w){
				path[v] += path[u];
				q.push({-dis[v],v});
				if(ans[u]+c[v] > ans[v]){
					ans[v] = ans[u] + c[v];
					pre[v] = u;
				}
			}
		}
	}
}
void print(int u){
	if(u==pre[u]){
		printf("%d",u);
		return ;
	}
	print(pre[u]);
	printf(" %d",u);
}
int main(void){
	scanf("%d%d%d%d",&n,&m,&S,&D);
	for(int i = 0;i < n;i++) scanf("%d",c+i),pre[i] = i;
	for(int i = 0;i < m;i++){
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	Dijkstra();
	printf("%d %d\n",path[D],ans[D]);
	print(D);
	printf("\n");
	return 0;
}
