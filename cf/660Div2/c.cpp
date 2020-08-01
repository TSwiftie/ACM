/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 01 Aug 2020 10:14:10 AM CST
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
const int N = 1e5+10;
vi G[N];
int p[N],h[N],a[N],g[N];
bool ok = true;
void dfs(int u,int f){
    a[u] = p[u];
    int sumg = 0;
    for(int v : G[u]) if(v!=f){
        dfs(v,u);
        sumg += g[v];
        a[u] += a[v];
    }
    if((a[u]+h[u])%2 != 0) ok = false;
    g[u] = (a[u] + h[u]) / 2;
    if(g[u] < 0 || g[u] > a[u]) ok = false;
    if(sumg > g[u]) ok = false;
}
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> p[i];
    for(int i = 1;i <= n;++i) cin >> h[i];
    for(int i = 1,u,v;i < n;++i){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    cout << (ok ? "YES" : "NO") << endl;
    ok = true;
    for(int i = 1;i <= n;++i) G[i].clear();
}
signed main(void){
    IOS;int T;
    for(cin >> T;T--;) solve();
    return 0;
}
