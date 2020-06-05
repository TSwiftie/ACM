/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 05 Jun 2020 08:57:25 AM CST
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
const int N = 5e5+10;
int n, m, num[N];
vi G[N],to[N],ans;
signed main(void){
	IOS;
	cin >> n >> m;
	for(int i = 1,u,v;i <= m;++i){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1,t;i <= n;++i){
		cin >> t;num[i] = 1;
		to[t].push_back(i);
	}
	for(int i = 1;i <= n;++i){
		for(int j : to[i]){
			if(num[j]!=i){
				cout << -1 << endl;
				return 0;
			}
			ans.push_back(j);
			for(int v : G[j])
				if(num[v]==i)
					num[v] = i+1;
		}
	}
	for(int v : ans)
		cout << v << ' ';
	cout << endl;
	return 0;
}
