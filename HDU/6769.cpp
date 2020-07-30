/************************************************************
	> File Name: 6769.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 30 Jul 2020 10:18:11 AM CST
************************************************************/
#include <algorithm>
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
const int N = 2e4+5,M = 25;
struct edge{ int v, a, b, next; }e[N<<1];
int head[N],tot,siz[N],n,m,T;
ll f[N][M],h[N],l,r,mid,ans;
inline void add_edge(int u,int v,int a,int b){ e[++tot].a = a;e[tot].b = b;e[tot].v = v;e[tot].next = head[u];head[u] = tot; }
inline void up(ll &a,ll b){ a > b ? (a=b) : 0; }
void dfs(int u,int fa){
    siz[u] = f[u][0] = 0;
    for(int i = head[u];i;i = e[i].next){
        int v = e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        int A = e[i].a,B = e[i].b,pre = siz[u],cur = siz[v],now = min(pre+cur+1,m);
        for(int j = 0;j <= now;++j) h[j] = mid+1;
        for(int j = 0;j <= pre;++j) for(int k = 0;k <= cur && j+k <= m;++k){
            if(f[u][j]+f[v][k]+A <= mid) up(h[j+k+1],max(f[u][j],f[v][k]+A));
            if(f[u][j]+f[v][k]+B <= mid) up(h[j+k],max(f[u][j],f[v][k]+B));
        }
        siz[u] = now;
        for(int j = 0;j <= now;++j) f[u][j] = h[j];
    }
}
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        l = r = tot = 0;
        for(int i = 0;i <= n;++i) head[i] = 0;
        for(int i = 1,u,v,a,b;i < n;++i){
            scanf("%d%d%d%d",&u,&v,&a,&b);
            add_edge(u,v,a,b);
            add_edge(v,u,a,b);
            r += max(a,b);
        }
        while(l <= r){
            mid = (l+r)>>1;
            dfs(1,0);
            if(f[1][m] <= mid) r = (ans=mid)-1;
            else l = mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
