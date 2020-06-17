/************************************************************
	> File Name: 3385.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 11:17:43 AM CST
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
const int N = 2e3+10;
const int M = 3e3+10;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
struct Edge{
	int v, w, next;
}e[M<<1];
int head[N],tot;
int n, m;
int dis[N],s[N];
bool vis[N];
void init(){
	memset(head,-1,sizeof head);
	memset(dis,INF,sizeof dis);
	memset(s,0,sizeof s);
	tot = 0;
}
void add_edge(int u,int v,int w){
	e[tot].v = v;
	e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot++;
}
queue<int>q;
bool spfa(){
	dis[1] = 0;
	q.push(1);
	while(q.size()){
		int u = q.front();
		q.pop();
		for(int i = head[u];~i;i = e[i].next){
			int v = e[i].v,w = e[i].w;
			if(dis[v] <= dis[u] + w) continue;
			if((s[v]++)+1==n) return true;
			dis[v] = dis[u] + w;
			q.push(v);
		}
	}
	return false;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		init();
		scanf("%d%d",&n,&m);
		for(int i = 1,u,v,w;i <= m;++i){
			scanf("%d%d%d",&u,&v,&w);
			if(w >= 0) add_edge(u,v,w),add_edge(v,u,w);
			else add_edge(u,v,w);
		}
		if(spfa()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
