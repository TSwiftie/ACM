/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 10 Aug 2020 03:53:30 PM CST
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
const int N = 5e4+10;
const int M = 5e5+10;
struct Edge{ int u,v,w,col; }e[M];
bool vis[N];int _,n,m,k,f[N];
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
void solve(){
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i = 1;i <= n;++i) f[i] = i,vis[i] = false;
    for(int i = 1;i <= m;++i) scanf("%lld%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w,&e[i].col);
    int cnt = 0,num = 0,ans = 0;
    sort(e+1,e+1+m,[](Edge a,Edge b){ return a.w > b.w; });
    for(int i = 1;i <= m;++i){
        if(e[i].col) continue;
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int fu = find(u),fv = find(v);
        ans += w;
        if(fu!=fv){
            f[fv] = fu;
            ++cnt;
        }
    }
    for(int i = 1;i <= m;++i){
        if(!e[i].col) continue;
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int fu = find(u),fv = find(v);
        if(fu!=fv){
            f[fv] = fu;
            ++cnt;++num;vis[i] = true;
            ans += w;
            if(num >= k){ printf("%lld\n",cnt==n-1?ans:-1);return; }
        }
    }
    for(int i = 1;i <= m;++i)
        if(e[i].col && num < k)
            if(!vis[i]) ans += e[i].w,++num;
    printf("%lld\n",cnt==n-1?ans:-1);
    return ;
}
signed main(void){
    for(scanf("%lld",&_);_--;) solve();
    return 0;
}
