/************************************************************
	> File Name: 3183.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 03:14:33 PM CST
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
const int N = 1e5+10;
int n,m,f[N],in[N],ans;
vi G[N];
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1,u,v;i <= m;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		in[v]++;
	}
	queue<int>q;
	for(int i = 1;i <= n;i++)
		if(!in[i]&&G[i].size()) q.push(i),f[i] = 1;
	while(q.size()){
		int u = q.front();
		q.pop();
		if(!G[u].size()) ans += f[u];
		for(int v : G[u]){
			f[v] += f[u];
			if(!--in[v]) q.push(v);
		}
	}
	printf("%d\n",ans);
	return 0;
}
