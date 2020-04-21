/************************************************************
	> File Name: 1066.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 02:04:37 PM CST
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
const int N = 1e4+10;
int n, m, s, t, dis, d[N], cnt;
struct Edge{
	int v,w,next;
}edge[500000];
int head[N],cur[N],tot = -1;
void add_edge(int u,int v,int w){
	edge[++tot].v = v;
	edge[tot].w = w;
	edge[tot].next = head[u];
	head[u] = tot;
}
int k, x[N], y[N], hi[1003][1003], zn[1003][1003];
char ch[202][202],sh[202][202];
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
			if(d[v]==-1&&edge[i].w){
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
int maxflow(){
	int flow = 0,f;
	while(bfs()){
		memcpy(cur,head,sizeof cur);
		while(f = dfs(s,INF))
			flow += f;
	}
	return flow;
}
signed main(void){
	memset(head,-1,sizeof head);
	scanf("%d%d%d",&n,&m,&dis);
	for(int i = 1;i <= n;i++){
		scanf("%s",ch[i]);
		for(int j = 0;j < m;j++){
			hi[i][j+1] = ch[i][j]-48;
			if(hi[i][j+1]!=0) k++,x[k] = i,y[k] = j+1,zn[i][j+1] = k;
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			if(hi[i][j]!=0)
				if(i <= dis || i+dis>n || j<=dis || j+dis>m)
					add_edge(zn[i][j]+k,2*k+1,INF),add_edge(2*k*1,zn[i][j]+k,0);
	for(int i = 1;i <= n;i++){
		scanf("%s",sh[i]);
		for(int j = 0;j < m;j++)
			if(sh[i][j]=='L'){
				int v = zn[i][j+1];
				cnt++;
				add_edge(0,v,1);
				add_edge(v,0,0);
			}
	}
	for(int i = 1;i <= k;i++)
		add_edge(i,i+k,hi[x[i]][y[i]]),add_edge(i+k,i,0);
	for(int i = 1;i <= k;i++)
		for(int j = 1;j <= k;j++){
			if(i==j) continue;
			if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]) <= dis*dis)
				add_edge(i+k,j,INF),add_edge(j,i+k,0);
		}
	s = 0,t = 2*k+1;
	printf("%d\n",cnt-maxflow());
	return 0;
}
