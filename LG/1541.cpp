/************************************************************
	> File Name: 1541.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 09 May 2020 07:45:49 PM CST
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
const int N = 55;
int dp[N][N][N][N],aa[351],g[5],n,m,x;
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",aa+i);
	dp[0][0][0][0] = aa[1];
	for(int i = 1;i <= m;i++){
		scanf("%d",&x);
		g[x]++;
	}
	for(int a = 0;a <= g[1];a++)
		for(int b = 0;b <= g[2];b++)
			for(int c = 0;c <= g[3];c++)
				for(int d = 0;d <= g[4];d++){
					int r = 1+a+b*2+c*3+d*4;
					if(a) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a-1][b][c][d]+aa[r]);
					if(b) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b-1][c][d]+aa[r]);
					if(c) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c-1][d]+aa[r]);
					if(d) dp[a][b][c][d] = max(dp[a][b][c][d],dp[a][b][c][d-1]+aa[r]);
				}
	printf("%d\n",dp[g[1]][g[2]][g[3]][g[4]]);
	return 0;
}
