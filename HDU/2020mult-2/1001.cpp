/************************************************************
	> File Name: 1001.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 23 Jul 2020 01:34:42 PM CST
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
vi G[N];
int b[N],f[N],idx[N],ans;
bool vis[N],del[N];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
bool cmp(int x,int y){
    return b[x] > b[y];
}
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int u,int f,vi &blo){
    vis[u] = true;
    blo.push_back(u);
    for(int v : G[u]) if(v!=f && !vis[v])
        dfs(v,u,blo);
}
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        int n, m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i) scanf("%d",b+i),f[i] = i,idx[i] = i;
        for(int i = 1,u,v;i <= m;++i){
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        for(int i = 1;i <= n;++i){
            if(!vis[i]){
                vi blo;
                dfs(i,0,blo);
                sort(all(blo),cmp);
                for(int u : blo){
                    del[u] = true;
                    for(int v : G[u]){
                        int fu = find(u),fv = find(v);
                        if(del[v]&&fu!=fv){
                            f[fu] = fv;
                            ans += b[idx[fv]] - b[u];
                        }
                    }
                    idx[find(u)] = u;
                }
                ans += b[blo.back()];
            }
        }
        printf("%d\n",ans);
        memset(vis,false,sizeof vis);
        memset(del,false,sizeof del);
        for(int i = 1;i <= n;++i) G[i].clear();
    }
    return 0;
}
