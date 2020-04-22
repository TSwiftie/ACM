/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 01:07:46 PM CST
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
const int N = 200005;
vi G[N];
int n, k, u, v, dep[N], siz[N], det[N];
ll ans;
bool cmp(int a,int b){
	return a > b;
}
int dfs(int u,int f){
	dep[u] = dep[f] + 1;siz[u] = 1;
	for(int v : G[u]) if(v!=f){
		siz[u] += dfs(v,u);
	}
	det[u] = siz[u]-dep[u];
	return siz[u];
}
signed main(void){
	scanf("%d%d",&n,&k);
	for(int i = 1;i < n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	nth_element(det+1,det+n-k,det+n+1,cmp);
	for(int i = 1;i <= n-k;i++) ans += det[i];
	printf("%lld\n",ans);
	return 0;
}
