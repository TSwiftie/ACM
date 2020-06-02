/************************************************************
	> File Name: LCA.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 02 Jun 2020 05:44:28 PM CST
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
const int N = 50007;
vi v[N],w[N];
int fa[N][31],cost[N][31],dep[N];
int n, m;
int a, b, c;
void dfs(int u,int f){
	fa[u][0] = f;
	dep[u] = dep[f] + 1;
	for(int i = 1;i < 31;++i){
		fa[u][i] = fa[fa[u][i-1]][i-1];
		cost[u][i] = cost[fa[u][i-1]][i-1] + cost[u][i-1];
	}
	int sz = SZ(v[u]);
	for(int i = 0;i < sz;++i){
		if(v[u][i]==f) continue;
		cost[v[u][i]][0] = w[u][i];
		dfs(v[u][i],u);
	}
}
signed main(void){
	return 0;
}
