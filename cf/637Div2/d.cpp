/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 27 Apr 2020 05:28:39 PM CST
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
const int N = 3e3+10,tab[] = {119,18,93,91,58,107,111,82,127,123};
int n, k, a[N],ans[N];
bool vis[N][N];
string s;
void dfs(int i,int x){
	if(x > k || vis[i][x]) return ;
	vis[i][x] = 1;
	if(i==n){
		if(x==k){
			for(int j = 0;j < n;j++) printf("%d",ans[j]);
			exit(0);
		}
		return ;
	}
	for(int j = 9;j >= 0;j--){
		ans[i] = j;
		if((tab[j]&a[i])==a[i]) dfs(i+1,x+__builtin_popcount(tab[j]^a[i]));
	}
}
signed main(void){
	IOS;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		cin >> s;
		for(char j : s) a[i] = (a[i]<<1) + (j-'0');
	}
	dfs(0,0);
	puts("-1");
	return 0;
}
