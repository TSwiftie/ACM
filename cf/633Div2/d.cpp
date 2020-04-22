/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 11:49:59 AM CST
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
int n, ans;
vi G[100006];
set<bool>s;
void dfs(int u,int fa,bool c){
	if(SZ(G[u])==1) s.insert(c);
	c ^= 1;
	for(int v : G[u]) if(v!=fa)
		dfs(v,u,c);
}
signed main(void){
	IOS;
	cin >> n;
	for(int i = 1;i < n;i++){
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,0);
	ans = n-1;
	for(int i = 1;i <= n;i++){
		int cnt = 0;
		for(int v : G[i])
			if(SZ(G[v])==1)
				cnt++;
		ans -= max(0,cnt-1);
	}
	cout << (SZ(s)==1 ? 1 : 3) << " " << ans << endl;
	return 0;
}
