/************************************************************
	> File Name: 4427.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 27 Jul 2020 06:44:17 PM CST
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
const int p = 998244353;
const int N = 3e5+5;
const int M = 55;
vi G[N];
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    return x*f;
}
inline int ksm(int a,int b){
    int ret = 1;
    while(b){
        if(b&1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}
void print(int x){
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
inline void add_edge(int u,int v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
}
int fa[N],dep[N],siz[N],son[N],dfn[N],top[N],idx,val[N][M];
void dfs1(int u,int f){
    dep[u] = dep[f] + 1;
    fa[u] = f;
    siz[u] = 1;
    for(int i = 0;i <= 50;++i)
        val[u][i] = (val[f][i] + ksm(dep[u]-1,i)) % p;
    for(int v : G[u]) if(v!=f){
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v] > siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u,int t){
    dfn[u] = ++idx;
    top[u] = t;
    if(son[u]) dfs2(son[u],t);
    for(int v : G[u]) if(v!=fa[u] && v!=son[u])
        dfs2(v,v);
}
inline int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]] < dep[top[v]])
            swap(u,v);
        u = fa[top[u]];
    }
    return dep[u] > dep[v] ? v : u;
}
signed main(void){
    int n,m,ans;
    n = read();
    for(int i = 1,u,v;i < n;++i){
        u = read();v = read();
        add_edge(u,v);
    }
    dfs1(1,0);
    dfs2(1,1);
    m = read();
    while(m--){
        int u = read(),v = read(),k = read();
        int f = lca(u,v);
        ans = (val[u][k] + val[v][k]) % p;
        ans -= (val[f][k] + val[fa[f]][k]) % p;
        ans = (ans + p) % p;
        print(ans);
        putchar(10);
    }
    return 0;
}
