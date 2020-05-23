/************************************************************
	> File Name: 11.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 31 Mar 2020 09:58:32 AM CST
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
const int dir[3][2] = {1,0,0,1,1,1};
int g[22][22];
signed main(void){
	for(int i = 1;i <= 20;i++)
		for(int j = 1;j <= 20;j++)
			scanf("%d",&g[i][j]);
	int ans = 0;
	for(int i = 1;i <= 17;i++)
		for(int j = 1;j <= 17;j++)
			for(int k = 0;k < 3;k++){
				int a = g[i][j];
				int b = g[i+dir[k][0]][j+dir[k][1]];
				int c = g[i+2*dir[k][0]][j+2*dir[k][1]];
				int d = g[i+3*dir[k][0]][j+3*dir[k][1]];
				ans = max(ans,a*b*c*d);
			}
	for(int i = 1;i <= 17;i++)
		for(int j = 20;j >= 4;j--){
			int a = g[i][j];
			int b = g[i+1][j-1];
			int c = g[i+2][j-2];
			int d = g[i+3][j-3];
			ans = max(ans,a*b*c*d);
		}
	printf("%d\n",ans);
	return 0;
}
