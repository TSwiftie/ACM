/************************************************************
	> File Name: 1005.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 28 Jul 2020 01:45:46 PM CST
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
const int p = 1e9+7;
int f[N],siz[N][3];
int find(int x){
    return x==f[x] ? x : f[x] = find(f[x]);
}
void solve(){
    int n;
    ll tr = 0,tc = 0;
    scanf("%d",&n);
    for(int i = 1,x;i <= n;++i){
        scanf("%d",&x);
        ++siz[i][x];
        tr += x==1;
        tc += x==2;
    }
    for(int i = 1,u,v;i < n;++i){
        scanf("%d%d",&u,&v);
        int fu = find(u),fv = find(v);
    }
}
signed main(void){
    int t;
    for(scanf("%d",&t);t--;) solve();
    return 0;
}
