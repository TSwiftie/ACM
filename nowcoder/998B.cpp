/************************************************************
	> File Name: 998A.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 08:25:34 PM CST
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
int n,m;
void dfs(int u,int sta){
	int tmp = sta,cnt=0;
	while(tmp){
		cnt += tmp&1;
		tmp >>= 1;
	}
	if(cnt==m){
		for(int i = 0;i < n;i++)
			if(sta>>i&1)
				cout << i+1 << " ";
		cout << endl;
		return ;
	}
	if(u==n) return ;
	dfs(u+1,sta|1<<u);
	dfs(u+1,sta);
}
signed main(void){
	scanf("%d%d",&n,&m);
	dfs(0,0);
	return 0;
}
