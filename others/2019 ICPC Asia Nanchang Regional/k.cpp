/************************************************************
	> File Name: k.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 10 Aug 2020 05:54:46 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <bits/extc++.h>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
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
const int N = 2e5+7;
int n, k;ll ans = 0;
vi G[N];int sz[N],d[N],son[N],w[N];
tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>t[N];
void dfs(int u){
    sz[u] = 1;
    for(int v : G[u]){
        d[v] = d[u] + 1;
        dfs(v);sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
void merge(int u,int lca){
    int x = 2*w[lca]-w[u];
    if(x>=0) ans += t[x].order_of_key(pii(2*d[lca]-d[u]+k,2e9));
    for(int v : G[u]) merge(v,lca);
}
void update(int u,int lca,int opt){
    if(opt==1) t[w[u]].insert(pii(d[u],u));
    else if(opt==-1) t[w[u]].erase(pii(d[u],u));
    for(int v : G[u]) update(v,lca,opt);
}
void dsu(int u,bool keep){
    for(int v : G[u]) if(v!=son[u]) dsu(v,0);
    if(son[u]) dsu(son[u],1);
    for(int v : G[u]) if(v!=son[u]){
        merge(v, u);update(v,u,1);
    }
    t[w[u]].insert(pii(d[u],u));
    if(!keep) update(u,u,-1);
}
signed main(void){
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;++i) scanf("%d",w+i);
    for(int i = 2,fa;i <= n;++i) scanf("%d",&fa),G[fa].push_back(i);
    dfs(1);dsu(1,1);
    printf("%lld\n",2*ans);
    return 0;
}
