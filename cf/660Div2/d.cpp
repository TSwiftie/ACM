/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 01 Aug 2020 04:57:34 PM CST
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
const int N = 2e5+10;
vi G[N],c,d;
ll a[N],ans;
int b[N];
void dfs(int u){
    for(int v : G[u]){
        dfs(v);
        if(a[v] >= 0) a[u] += a[v];
    }
    if(a[u] >= 0) c.push_back(u);
    else d.push_back(u);
    ans += a[u];
}
signed main(void){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) scanf("%lld",a+i);
    for(int i = 1;i <= n;++i){
        scanf("%d",b+i);
        if(~b[i]) G[b[i]].push_back(i);
    }
    for(int i = 1;i <= n;++i)
        if(b[i]==-1) dfs(i);
    printf("%lld\n",ans);
    for(int &i : c) printf("%d ",i);
    for(int i = SZ(d)-1;i >= 0;--i) printf("%d%c",d[i]," \n"[i==0]);
    return 0;
}
