/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 17 May 2020 08:28:11 PM CST
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
const int N = 1e5+10;
int n, m;
vi G[N];
int dis[N];
bool vis[N];
signed main(void){
	IOS;
	cin >> n >> m;
	for(int i = 1,u,v;i <= m;i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	memset(dis,INF,sizeof dis);
	dis[1] = 0;
	queue<int>q;
	q.push(1);
	while(q.size()){
		int u = q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(int v : G[u]){
			dis[v] = min(dis[v],dis[u]+1);
			q.push(v);
		}
	}
	bool ok = true;
	for(int i = 1;i <= n;i++)
		ok &= vis[i];
	if(!ok) cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		for(int i = 2;i <= n;i++)
			cout << dis[i] << endl;
	}
	return 0;
}
