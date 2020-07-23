/************************************************************
	> File Name: 6756.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 23 Jul 2020 09:51:29 AM CST
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
vi g[N],now[N];
set<int>s[N];
int in[N],num[110][N],id[N],a[N];
bool st[N];
signed main(void){
    IOS;
    int T;
    for(cin >> T;T--;){
        int n, m;
        cin >> n >> m;
        for(int i = 1;i <= n;++i){
            cin >> a[i];
            g[i].clear();
            in[i] = 0;
            now[i].clear();
        }
        int block = 1000;
        for(int i = 1,u,v;i <= m;++i){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            ++in[u];++in[v];
        }
        int cnt = 0;
        for(int i = 1;i <= n;++i){
            if(in[i] >= block){
                id[i] = ++cnt;
                s[cnt].clear();
                for(int j = 0;j <= in[i];++j) s[cnt].insert(j),num[cnt][j] = 0;
            }
        }
        for(int i = 1;i <= n;++i)
            for(int j : g[i])
                if(in[j] >= block)
                    if(a[i] <= in[j]){
                        if(++num[id[j]][a[i]]==1)
                            s[id[j]].erase(a[i]);
                        now[i].push_back(j);
                    }
        int q,op,u,v;
        cin >> q;
        while(q--){
            cin >> op;
            if(op==1){
                cin >> u >> v;
                for(int tmp : now[u]){
                    if(v <= in[tmp])
                        if(++num[id[tmp]][v]==1) s[id[tmp]].erase(v);
                    if(a[u] <= in[tmp])
                        if(--num[id[tmp]][a[u]]==0) s[id[tmp]].insert(a[u]);
                }
                a[u] = v;
            }else{
                cin >> u;
                if(in[u] >= block) cout << *s[id[u]].begin() << endl;
                else{
                    for(int v : g[u])
                        if(a[v] <= in[u]) st[a[v]] = true;
                    int ans = 0;
                    while(st[ans]) ++ans;
                    cout << ans << endl;
                    for(int v : g[u])
                        if(a[v] <= in[u]) st[a[v]] = false;
                }
            }
        }
    }
    return 0;
}
