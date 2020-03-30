/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 30 Mar 2020 06:37:07 PM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 2e5+10;
vi G[N];
int tin[N],tout[N];
int dep[N],fa[N],T;
void dfs(int u,int f = -1,int d = 0){
	dep[u] = d;
	fa[u] = f;
	tin[u] = T++;
	for(int v : G[u]) if(v!=f)
		dfs(v,u,d+1);
	tout[u] = T++;
}
bool jugde(int u,int v){
	return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}
signed main(void){
	int n, m;
	cin >> n >> m;
	for(int i = 0,x,y;i < n-1;i++){
		cin >> x >> y;
		x--;y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(0);
	for(int i = 0,k;i < m;i++){
		cin >> k;
		vi v(k);
		for(int &it : v){
			cin >> it;
			it--;
		}
		int u = v[0];
		for(int it : v) if(dep[u] < dep[it]) u = it;
		for(int &it : v) if(it!=u && fa[it]!=-1) it = fa[it];
		bool ok = true;
		for(int it : v) ok &= jugde(it,u);
		cout << (ok?"YES":"NO") << endl;
	}
	return 0;
}
