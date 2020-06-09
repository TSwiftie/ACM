/************************************************************
	> File Name: P1462.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 29 Aug 2019 02:48:20 PM CST
************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e4+5;
const int MAXM = 1e5+5;
struct node{
	int to,val,next;
}edge[MAXM];
int cnt,head[MAXN],n,m,hp,f[MAXN],u[MAXN],dis[MAXN];
bool vis[MAXN];
void add_edge(int u,int v,int w){
	edge[++cnt].to = v;
	edge[cnt].val = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
}
bool check(int top){
	memset(dis,INF,sizeof dis);
	memset(vis,false,sizeof vis);
	queue<int>q;
	dis[1] = 0;
	vis[1] = true;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u]+edge[i].val && f[v] <= top){
				dis[v] = dis[u] + edge[i].val;
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	if(dis[n] <= hp)
		return true;
	else
		return false;
}
int main(void){
	scanf("%d%d%d",&n,&m,&hp);
	for(int i = 1;i <= n;i++){
		scanf("%d",f+i);
		u[i] = f[i];
	}
	for(int i = 1;i <= m;i++){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	sort(u+1,u+1+n);
	if(check(INF)==false){
		printf("AFK\n");
	}else{
		int l = 1,r = n;
		int mid,ans = 0;
		while(l < r){
			mid = (l+r)>>1;
			if(check(u[mid])) r = mid;
			else l = mid+1;
		}
		printf("%d\n",u[l]);
	}
	return 0;
}
