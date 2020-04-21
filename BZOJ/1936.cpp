/************************************************************
	> File Name: 3376.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 10:51:17 AM CST
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
const int N = 330;
const int M = 1e6+10;
struct Edge{
	int v,w,next;
}edge[M];
int head[N],cur[N],tot = -1;
void add_edge(int u,int v,int w){
	edge[++tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot;
}
int d[N],s,t,n,m;
bool bfs(){
	memset(d,-1,sizeof d);
	queue<int>q;
	q.push(s);
	d[s] = 0;
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i = head[u];~i;i = edge[i].next){
			int v = edge[i].v;
			if(edge[i].w && d[v]==-1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return ~d[t];
}
int dfs(int u,int a){
	if(u==t||a==0) return a;
	int flow = 0,f;
	for(int &i = cur[u];~i;i = edge[i].next){
		int v = edge[i].v;
		if(d[v]==d[u]+1&&(f = dfs(v,min(a,edge[i].w)))){
			edge[i].w -= f;
			edge[i^1].w += f;
			flow += f;
			a -= f;
			if(!a) break;
		}
	}
	return flow;
}
int maxflow(int s,int t){
	int ans = 0,f;
	while(bfs()){
		memcpy(cur,head,sizeof cur);
		while(f = dfs(s,INF))
			ans += f;
	}
	return ans;
}
signed main(void){
	memset(head,-1,sizeof head);
	scanf("%d%d",&n,&m);
	s = n+1,t = n+2;
	for(int i = 1,B;i <= n;i++){
		scanf("%d",&B);
		if(B) add_edge(i,t,1),add_edge(t,i,0);
		else add_edge(s,i,1),add_edge(i,s,0);
	}
	for(int i = 1;i <= m;i++){
		int u, v;
		scanf("%d%d",&u,&v);
		add_edge(u,v,1);add_edge(v,u,0);
		add_edge(v,u,1);add_edge(u,v,0);
	}
	printf("%d\n",maxflow(s,t));
	return 0;
}
