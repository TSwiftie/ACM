/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 10:41:44 AM CST
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
#define int long long
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
const int N = 120000;
const int M = 120000;
struct node{
	int v, k, w;
};
vector<node> G[N];
int n, m, H, dis[N];
int check(int x){
	priority_queue<pair<int,int> > q;
	memset(dis,INF,sizeof dis);
	dis[1] = 0;
	q.push({0,1});
	while(q.size()){
		int u = q.top().second;
		q.pop();
		for(node vn : G[u]){
			if(dis[vn.v] > dis[u] + vn.k*x + vn.w){
				dis[vn.v] = dis[u] + vn.k*x + vn.w;
				q.push({-dis[vn.v],vn.v});
			}
		}
	}
	return dis[n];
}
signed main(void){
	IOS;
	cin >> n >> m >> H;
	for(int i = 1;i <= m;++i){
		int u, v, k, w;
		cin >> u >> v >> k >> w;
		G[u].push_back({v,k,w});
	}
	int l = 0,r = H,ans = -INF;
	while(l < r){
		int m1 = l+(r-l)/3,m2 = r-(r-l)/3;
		int p = check(m1),q = check(m2);
		ans = max(ans,max(p,q));
		if(p > q) r = m2-1;
		else l = m1+1;
	}
	cout << ans << endl;
	return 0;
}
