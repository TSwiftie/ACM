/************************************************************
	> File Name: 3478.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: jue 09 jul 2020 16:35:33
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
const int N = 1e6+10;
int n,id;
vi G[N];
ll ans,f[N],dep[N],siz[N];
void dfs1(int u,int fa){
    siz[u] = 1;
    dep[u] = dep[fa] + 1;
    for(int v : G[u]) if(v!=fa){
        dfs1(v,u);
        siz[u] += siz[v];
    }
}
void dfs2(int u,int fa){
    for(int v : G[u]) if(v!=fa){
        f[v] = f[u] - (siz[v]<<1) + n;
        dfs2(v,u);
    }
}
signed main(void){
    scanf("%d",&n);
    for(int i = 1,u,v;i < n;++i){
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,1);
    for(int i = 1;i <= n;++i) f[1] += dep[i];
    dfs2(1,1);
    for(int i = 1;i <= n;++i) if(f[i] > ans) ans = f[i],id = i;
    printf("%d\n",id);
    return 0;
}
