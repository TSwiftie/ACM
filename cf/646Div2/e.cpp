/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 02 Jun 2020 10:19:44 AM CST
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
const int N = 2e5+10;
vi G[N];
int n, a[N], b[N], c[N], c1[N], c2[N], ans;
inline void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
void dfs(int u,int f){
	a[u] = min(a[u],a[f]);
	for(int v : G[u]) if(v!=f){
		dfs(v,u);
		c1[u] += c1[v];c2[u] += c2[v];
	}
	if(b[u]!=c[u]){
		if(b[u]) ++c2[u];
		else ++c1[u];
	}
	int x = min(c1[u],c2[u]);
	ans += 2LL*x*a[u];
	c1[u] -= x;
	c2[u] -= x;
}
signed main(void){
	IOS;
	cin >> n;
	a[0] = INF_ll;
	for(int i = 1;i <= n;++i)
		cin >> a[i] >> b[i] >> c[i];
	for(int i = 1,u,v;i < n;++i){
		cin >> u >> v;
		add_edge(u,v);
	}
	dfs(1,0);
	if(c1[1]||c2[1]) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
