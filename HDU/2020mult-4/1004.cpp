/************************************************************
	> File Name: 1004.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 30 Jul 2020 01:16:00 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
struct Edge{
    int v,w,next;
}e[N<<1];
int head[N],tot,d[N],n,m,s,t,x,T;
char sta[N];
bool vis[N];
void add_edge(int u,int v,int w){
    e[++tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;
}
void Dijkstra(){
    memset(d,0x3f,sizeof d);
    memset(vis,false,sizeof vis);
    d[s] = 0;
    priority_queue<pll>q;
    q.push(make_pair(-d[s],s));
    while(q.size()){
        int u = q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u];i;i = e[i].next){
            int v = e[i].v,w = e[i].w;
            if(sta[v]=='M' && d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push(make_pair(-d[v],v));
            }else if(sta[v]!=sta[u] && d[v] > d[u] + x + w){
                d[v] = d[u] + w + x;
                q.push(make_pair(-d[v],v));
            }else if(sta[v]==sta[u] && d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push(make_pair(-d[v],v));
            }
        }
    }
}
void solve(){
    tot = 0;
    memset(head,0,sizeof head);
    cin >> n >> m >> s >> t >> x;
    cin >> (sta+1);
    for(int i = 1,u,v,w;i <= m;++i){
        cin >> u >> v >> w;
        add_edge(u,v,w);
        add_edge(v,u,w);
    }
    Dijkstra();
    cout << d[t] << endl;
}
signed main(void){
    IOS;
    for(cin >> T;T--;) solve();
    return 0;
}
