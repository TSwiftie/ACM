#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int INF = 0x3f3f3f3f;
const int M = N*N;
struct Edge {
    int v,w,next;
}edge[M];
int n, m, c1, c2;
int head[N],tot;
int dis[N],maxsu[N],su[N],pat[N];
bool vis[N];
void add_edge(int u,int v,int w){
    edge[++tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot;
}
void Dijkstra(int S){
    for(int i = 0;i < n;++i) dis[i] = INF,vis[i] = false;
    dis[S] = 0;maxsu[S] = su[S];pat[S] = 1;
    priority_queue<pair<int,int>>q;
    q.push({-dis[S],S});
    while(q.size()){
        int u = q.top().second;q.pop();
        if(vis[u]) continue; vis[u] = true;
        for(int i = head[u];i;i = edge[i].next){
            int v = edge[i].v,w = edge[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                maxsu[v] = maxsu[u] + su[v];
                pat[v] = pat[u];
                q.push({-dis[v],v});
            }else if(dis[v] == dis[u] + w){
                pat[v] += pat[u];
                maxsu[v] = max(maxsu[v], maxsu[u] + su[v]);
                q.push({-dis[v],v});
            }
        }
    }
}
signed main(void){
    scanf("%d %d %d %d",&n, &m, &c1, &c2);
    for(int i = 0;i < n;++i) scanf("%d",su+i);
    for(int i = 1,u,v,w;i <= m;++i){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    Dijkstra(c1);
    printf("%d %d\n",pat[c2], maxsu[c2]);
    return 0;
}
