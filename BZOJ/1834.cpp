/************************************************************
	> File Name: 1834.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 04:24:29 PM CST
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
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(f=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
int n, m, tot = -1, ans, k, head[1010],dis[1010],vis[1010];
struct Edge{
	int to,next,w,cap;
}edge[25010];
inline void add_edge(int u,int v,int w,int cap){
	edge[++tot].to = v;
	edge[tot].w = w;
	edge[tot].cap = cap;
	edge[tot].next = head[u];
	head[u] = tot;
}
inline void add(int u,int v,int w,int cap){
	add_edge(u,v,w,cap);
	add_edge(v,u,-w,0);
}
bool spfa(int s,int t){
	queue<int>q;
	memset(dis,-1,sizeof dis);
	memset(vis,false,sizeof vis);
	dis[t] = 0;
	vis[t] = true;
	q.push(t);
	while(q.size()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];~i;i = edge[i].next){
			int v = edge[i].to,w = edge[i].w;
			if(edge[i^1].cap&&((dis[v]==-1)||dis[v]>dis[u]-w)){
				dis[v] = dis[u]-w;
				if(!vis[v]) q.push(v),vis[v] = true;
			}
		}
	}
	return ~dis[s];
}
int dfs(int u,int t,int a){
	if(u==t){
		vis[t] = true;
		return a;
	}
	if(!a){
		vis[u] = true;
		return a;
	}
	int flow = 0,f;
	vis[u] = true;
	for(int i = head[u];~i;i = edge[i].next){
		int v = edge[i].to,w = edge[i].w;
		if((dis[v]==dis[u]-w)&&(!vis[v])&&edge[i].cap){
			f = dfs(v,t,min(a,edge[i].cap));
			if(!f) continue;
			edge[i].cap -= f;
			edge[i^1].cap += f;
			flow += f;
			a -= f;
			ans += edge[i].w*f;
			if(!a) return flow;
		}
	}
	return flow;
}
int zkw(int s,int t){
	int re = 0;
	while(spfa(s,t)){
		vis[t] = 1;
		while(vis[t]){
			memset(vis,false,sizeof vis);
			re += dfs(s,t,0x7f7f7f7f);
		}
	}
	return re;
}
int cost[5010],u[5010],v[5010],cap[5010];
signed main(void){
	int maxflow;
	memset(head,-1,sizeof head);
	n = read();m = read();k = read();
	for(int i = 1;i <= m;i++){
		u[i] = read();v[i] = read();cap[i] = read();cost[i] = read();
		add(u[i],v[i],0,cap[i]);
	}
	printf("%d ",maxflow = zkw(1,n));
	memset(head,-1,sizeof head);
	tot = -1;
	for(int i = 1;i <= m;i++){
		add(u[i],v[i],0,cap[i]);
		add(u[i],v[i],cost[i],0x7f7f7f7f);
	}
	add(n,n+1,0,maxflow+k);
	zkw(1,n+1);
	printf("%d\n",ans);
	return 0;
}
