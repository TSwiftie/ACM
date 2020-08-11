/************************************************************
	> File Name: 1007.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 11 Aug 2020 01:36:58 PM CST
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
const int N = 2e3+10;
int _,n;double x[N],y[N];bool vis[N];
typedef pair<double,int>pdi;
vector<pdi>e[N];
inline double dis(int i,int j){ return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])); }
void dfs(int u,double last){
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%lf%lf",x+i,y+i);
    for(int i=1;i<n;++i){
        for(int j=1;j<=n;++j) 
            e[i].push_back(pdi(dis(i,j),j)),e[j].push_back(pdi(dis(i,j),i));
        sort(all(e[i]),[](pdi a,pdi b){ return a.first < b.first; });
    }
    dfs(1,0);
    memset(vis,false,sizeof vis);
}
signed main(void){
    for(scanf("%d",&_);_--;) solve();
    return 0;
}
