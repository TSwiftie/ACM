/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 24 Mar 2020 10:28:01 AM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
vi G[MAXN];
void solve(){
	int n;
	scanf("%d",&n);
	set<int>s;
	for(int i = 1;i <= n;i++) s.insert(s);
	for(int i = 1,x,v;i <= n;i++){
		scanf("%d",&x);
		while(x--){
			scanf("%d",&v);
			G[i].push_back(v);
		}
	}
	vi lost;
	for(int i = 1;i <= n;i++){
	}
}
signed main(void){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
