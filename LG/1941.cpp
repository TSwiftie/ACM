/************************************************************
	> File Name: 1941.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 12 May 2020 07:54:42 PM CST
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
const int N = 1e4+10;
const int M = 2e3+10;
int n, m, p;
int x[N],y[N];
int l[N],h[N];
int f[N][M];
bool e[N];
signed main(void){
	scanf("%d%d%d",&n,&m,&p);
	for(int i = 1;i <= n;i++) scanf("%d%d",x+i,y+i);
	for(int i = 1;i <= n;i++){
		l[i] = 1;
		h[i] = m;
	}
	int a, b, c;
	for(int i = 1;i <= p;i++){
		scanf("%d%d%d",&a,&b,&c);
		e[a] = 1;
		l[a] = b+1;
		h[a] = c-1;
	}
	memset(f,0x3f,sizeof f);
	for(int i = 1;i <= m;i++) f[0][i] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = x[i]+1;j <= m+x[i];j++)
			f[i][j] = min(f[i-1][j-x[i]],f[i][j-x[i]])+1;
		for(int j = m+1;j <= m+x[i];j++)
			f[i][m] = min(f[i][m],f[i][j]);
		for(int j = 1;j <= m-y[i];j++)
			f[i][j] = min(f[i][j],f[i-1][j+y[i]]);
		for(int j = 1;j < l[i];j++)
			f[i][j] = f[0][0];
		for(int j = h[i]+1;j <= m;j++)
			f[i][j] = f[0][0];
	}
	int ans = f[0][0];
	for(int i = 1;i <= m;i++)
		ans = min(ans,f[n][i]);
	if(ans < f[0][0]) printf("1\n%d\n",ans);
	else{
		int i, j;
		for(i = n;i >= 1;i--){
			for(j = 1;j <= m;j++)
				if(f[i][j] < f[0][0]) break;
			if(j <= m) break;
		}
		ans = 0;
		for(int j = 1;j <= i;j++)
			if(e[j]) ans++;
		printf("0\n%d\n",ans);
	}
	return 0;
}
