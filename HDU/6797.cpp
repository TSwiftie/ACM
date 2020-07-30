/************************************************************
	> File Name: 1007.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 29 Jul 2020 06:02:02 PM CST
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
const int N = 52;
int n, m, k, e[N][N], pre[N], res, d[N];
bool vis[N];
void Dijkstra(int *pre){
    memset(vis,false,sizeof vis);
    memset(d,INF,sizeof d);
    d[1] = 0;
    for(int i = 1;i < n;++i){
        int minx = INF,u = 0;
        for(int j = 1;j <= n;++j) if(!vis[j] && d[j] < minx) u = j,minx = d[j];
        vis[u] = true;
        for(int j = 1;j <= n;++j){
            if(e[u][j] < INF && !vis[j] && d[j] > d[u] + e[u][j])
                pre[j] = u,d[j] = d[u] + e[u][j];
        }
    }
}
void dfs(int dep){
    if(dep==k+1){
        Dijkstra(pre);
        res = max(res,d[n]);
        return ;
    }
    int pre[N] = {0};
    Dijkstra(pre);
    int now = n;
    while(pre[now]){
        int tmp = e[pre[now]][now];
        e[pre[now]][now] = e[now][pre[now]] = INF;
        dfs(dep+1);
        e[pre[now]][now] = e[now][pre[now]] = tmp;
        now = pre[now];
    }
}
void solve(){
    scanf("%d%d",&n,&k);
    m = n*(n-1)/2;
    res = 0;
    for(int i = 1,u,v,w;i <= m;++i){
        scanf("%d%d%d",&u,&v,&w);
        e[u][v] = e[v][u] = w;
    }
    dfs(1);
    printf("%d\n",res);
}
signed main(void){
    int T;
    for(scanf("%d",&T);T--;) solve();
    return 0;
}
