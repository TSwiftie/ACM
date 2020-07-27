/************************************************************
	> File Name: 1131.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 27 Jul 2020 07:52:38 PM CST
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
const int N = 5e5+5;
struct Edge{
    int v,w,next;
}e[N<<2];
int n,rt;
int head[N],tot;
ll ans,dis[N];
inline void init(){
    memset(head,-1,sizeof head);
    tot = 0;
}
void add_edge(int u,int v,int w){
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u,int f){
    for(int i = head[u];~i;i = e[i].next){
        int v = e[i].v,w = e[i].w;
        if(v==f) continue;
        dfs(v,u);
        dis[u] = max(dis[u],dis[v] + w);
    }
    for(int i = head[u];~i;i = e[i].next){
        int v = e[i].v,w = e[i].w;
        if(v==f) continue;
        ans += dis[u] - (dis[v] + w);
    }
}
signed main(void){
    init();
    scanf("%d%d",&n,&rt);
    for(int i = 1,u,v,w;i < n;++i){
        scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    dfs(rt,0);
    printf("%lld\n",ans);
    return 0;
}
