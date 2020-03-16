/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 16 Mar 2020 10:59:19 AM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
vi G[MAXN];
int n,ans[MAXN];
signed main(void){
	scanf("%d",&n);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(i);
		G[v].push_back(i);
		ans[i] = -1;
	}
	pii mx(0,0);
	for(int i = 1;i <= n;i++)
		mx = max(mx,make_pair((int)G[i].size(),i));
	int cur = 0;
	for(int i : G[mx.second])
		ans[i] = cur++;
	for(int i = 1;i < n;i++){
		if(ans[i]==-1)
			ans[i] = cur++;
		printf("%d\n",ans[i]);
	}
	return 0;
}
