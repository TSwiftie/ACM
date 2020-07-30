/************************************************************
	> File Name: 6805.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 30 Jul 2020 07:49:08 PM CST
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
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e5+10;
const int M = N<<1+5;
struct Edge{
    int v,w,next;
}edge[M<<1];
int n, m, s, t, cost, head[M], tot;
char ch[N];
int S, T, nv;
ll dis[M];
bool vis[M];
void add_edge(int u,int v,int w){
    edge[++tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot;
    edge[++tot].v = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot;
}
priority_queue<pair<ll,int>>q;
ll Dijkstra(){
    memset(dis,0x3f,sizeof dis);
    memset(vis,false,sizeof vis);
    dis[S] = 0;
    q.push(make_pair(-dis[S],S));
    while(q.size()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u];i;i = edge[i].next){
            int v = edge[i].v,w = edge[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
    return dis[T];
}
inline bool Conflict(int t,char c){
    return (t==0 && c=='R') || (t==1 && c=='L');
}
void solve(){
    scanf("%d%d%d%d%d",&n,&m,&s,&t,&cost);
    --s;--t;
    scanf("%s",ch);
    nv = n*2+2;tot = 0;
    for(int i = 0;i < nv;++i) head[i] = 0;
    for(int i = 0,u,v,w;i < m;++i){
        scanf("%d%d%d",&u,&v,&w);
        --u;--v;
        for(int tu = 0;tu <= 1;++tu){
            if(Conflict(tu,ch[u])) continue;
            for(int tv = 0;tv <= 1;++tv){
                if(Conflict(tv,ch[v])) continue;
                add_edge(u<<1|tu,v<<1|tv,w+(tu!=tv)*cost);
            }
        }
    }
    S = n<<1,T = S+1;
    for(int ts = 0;ts <= 1;++ts){
        if(Conflict(ts,ch[s])) continue;
        add_edge(S,s<<1|ts,0);
    }
    for(int tt = 0;tt <= 1;++tt){
        if(Conflict(tt,ch[t])) continue;
        add_edge(T,t<<1|tt,0);
    }
    printf("%lld\n",Dijkstra());
}
signed main(void){
    int T;
    for(scanf("%d",&T);T--;) solve();
    return 0;
}
