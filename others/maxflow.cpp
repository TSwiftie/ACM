/************************************************************
	> File Name: maxflow.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 10:38:09 AM CST
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
const int N = 1e5+10;
const int M = 2e5+10;
struct Max_Flow{
	int head[N],nxt[M],des[M],c[M],tot;
	int dep[N],ss,tt;
	Max_Flow() {
		clear();
	}
	void clear(){
		memset(head,-1,sizeof head);tot = -1;
	}
	inline void add_edge(int u,int v,int w){
		des[++tot] = v;
		c[tot] = w;
		nxt[tot] = head[u];
		head[u] = tot;
	}
	bool bfs(){
		memset(dep,-1,sizeof dep);
		dep[ss] = 0;
		queue<int>q;
		q.push(ss);
		while(q.size()){
			int u = q.front();q.pop();
			for(int i = head[u];~i;i = nxt[i]){
				int v = des[i],cx = c[i];
				if(dep[v]==-1&&cx){
					dep[v] = dep[u] + 1;
					q.push(v);
				}
			}
		}
		return dep[tt]!=-1;
	}
	int dfs(int u,int now){
		if(u==tt) return now;
		int res = 0;
		for(int i = head[u];~i&&res < now;i = nxt[i]){
			int v = des[i],cx = c[i];
			if(dep[v]==dep[u]+1&&cx){
				int x = min(cx,now-res);
				x = dfs(v,x);
				res += x;c[i]-=x;c[i^1] += x;
			}
		}
		if(!res) dep[u] = -2;
		return res;
	}
	void init(vector<tuple<int,int,int> > Edge){
		for(auto tp : Edge){
			int u,v,w;tie(u,v,w) = tp;
			add_edge(u,v,w);
			add_edge(v,u,0);
		}
	}
	ll maxflow(int s,int t){
		ss = s;tt = t;
		ll res = 0,del = 0;
		while(bfs())
			while(del = dfs(ss,INF))
				res += del;
		return res;
	}
}net;
int n, m, s, t;
vector<tuple<int,int,int> >E;
signed main(void){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i = 0;i < m;i++){
		int u, v, w;
		scanf("%d%d%d",&u,&v,&w);
		E.push_back(make_tuple(u,v,w));
	}
	net.init(E);
	printf("%lld\n",net.maxflow(s,t));
	return 0;
}
