/************************************************************
	> File Name: 1001.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 23 Jul 2020 08:28:46 PM CST
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
int T, n, m, f[N], b[N], q[N], fa[N];
vi G[N];
bool add[N];
bool cmp(int x,int y){ return b[x] > b[y]; }
int find(int x){ return f[x]==x ? x : f[x] = find(f[x]); }
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i){
            scanf("%d",b+i);
            G[i].clear();
            f[i] = q[i] = i;
            add[i] = false;
            fa[i] = 0;
        }
        for(int i = 1,u,v;i <= m;++i){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        sort(q+1,q+1+n,cmp);
        for(int i = 1;i <= n;++i){
            int u = q[i];
            add[u] = true;
            for(int v : G[u]){
                if(!add[v]) continue;
                v = find(v);
                if(v==u) continue;
                fa[v] = f[v] = u;
            }
        }
        ll ans = 0;
        for(int i = 1;i <= n;++i) ans += b[i] - b[fa[i]];
        printf("%lld\n",ans);
    }
    return 0;
}
