/************************************************************
	> File Name: 998C.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 08:40:53 PM CST
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
int n,ans[20];
bool vis[20];
void dfs(int dep){
	if(dep==n+1){
		for(int i = 1;i < dep;i++)
			cout << ans[i] << " ";
		cout << endl;
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(!vis[i]){
			vis[i] = true;
			ans[dep] = i;
			dfs(dep+1);
			ans[dep] = 0;
			vis[i] = false;
		}
	}
}
signed main(void){
	scanf("%d",&n);
	dfs(1);
	return 0;
}
