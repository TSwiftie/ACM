/************************************************************
	> File Name: 3358.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 03 Aug 2020 11:06:59 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
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
const int N = 2e5+10;
struct Edge{ int u,v,f,c,next; }e[N<<1];
int S,T,ans,res,cnt,n,m,g[N],vis[N],dis[N],pre[N],head[N],last[N];
queue<int>q;
void add_edge(int u,int v,int f,int c){ e[++cnt].u = u;e[cnt].v = v;e[cnt].f = f;e[cnt].c = c;e[cnt].next = head[u];head[u] = cnt; }
bool spfa(){
    fill(g,g+n+1,INF);
    fill(dis,dis+n+1,INF);
    fill(vis,vis+n+1,0);
    q.push(S); vis[S] = 1;dis[S] = 0;
    while(q.size()){
        int u = q.front();q.pop();vis[u] = 0;
        for(int i = head[u];~i;i = e[i].next){
            int v = e[i].v;
            if(dis[v] > dis[u] + e[i].c && e[i].f){
                dis[v] = dis[u] + e[i].c;
                g[v] = min(g[e[i].f],g[u]);
                pre[v] = u;
                last[v] = i;
                if(!vis[v]){ q.push(v);vis[v] = 1; }
            }
        }
    }
    return dis[T] < INF;
}
void ek(){
    while(spfa()){
        int x = T;
        res += g[T];
        ans += g[T]*dis[T];
        while(x!=S){
            e[last[x]].f -= g[T];
            e[last[x]^1].f += g[T];
            x = pre[x];
        }
    }
}
int len[N];
pii base[N];
int _n,_k,tot;
map<int,int>Id,buc;
signed main(void){
    scanf("%d%d",&_n,&_k); cnt = -1;
    memset(head,-1,sizeof head);
    for(int i = 1;i <= _n;++i){
        scanf("%d%d",&base[i].first,&base[i].second);
        len[i] = base[i].second-base[i].first;
    }
    for(int i = 1;i <= _n;++i){
        if(!Id.count(base[i].first)) ++buc[base[i].first];
        if(!Id.count(base[i].second)) ++buc[base[i].second];
    }
    add_edge(0,1,_k,0);add_edge(1,0,0,0);
    for(auto it : buc) Id[it.first] = ++tot;
    S = 0,T = tot+1;
    for(int i = 1;i <= tot;++i) add_edge(i,i+1,INF,0),add_edge(i+1,i,0,0);
    for(int i = 1;i <= _n;++i){
        add_edge(Id[base[i].first],Id[base[i].second],1,-len[i]);
        add_edge(Id[base[i].second],Id[base[i].first],0,len[i]);
    }
    n = T+1; ek();
    printf("%d\n",-ans);
    return 0;
}
/*
 *
 *
 *
 * hello world
 *TSwiftie
 *TSwiftie
 *
 *
 * adjaskdjalksdjasd
 * adkasjdlkasd
 * akdjaslkdjlkasd
 * akdlaksjdklasd
 * akjlakjsdsadd
 *
 * 
 */
