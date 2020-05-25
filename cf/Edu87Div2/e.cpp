/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 25 May 2020 06:26:42 PM CST
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
const int N = 5005;
vi G[N];
int n, m, n1, n2, n3, p[N], x[N];
int cnt, d1[N], d2[N];
bool dp[N][N],rev[N];
void dfs(int u){
	if(x[u]==1) d1[cnt]++;
	else d2[cnt]++;
	for(int v : G[u]){
		if(!x[v]){
			x[v] = 3-x[u];
			p[v] = cnt;
			dfs(v);
		}else if(x[u]==x[v]){
			puts("NO");
			exit(0);
		}
	}
}
signed main(void){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&n1,&n2,&n3);
	for(int i = 1,u,v;i <= m;++i){
		scanf("%d%d",&u,&v);
		--u,--v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cnt = 0;
	dp[0][0] = true;
	for(int i = 0;i < n;++i) if(!x[i]){
		p[i] = cnt;
		x[i] = 1;
		dfs(i);
		for(int j = d1[cnt];j <= n2;++j)
			dp[cnt+1][j] |= dp[cnt][j-d1[cnt]];
		for(int j = d2[cnt];j <= n2;++j)
			dp[cnt+1][j] |= dp[cnt][j-d2[cnt]];
		cnt++;
	}
	if(!dp[cnt][n2]){
		puts("NO");
		return 0;
	}
	puts("YES");
	while(cnt--){
		rev[cnt] = !dp[cnt][n2-d2[cnt]];
		if(rev[cnt]) n2 -= d1[cnt];
		else n2 -= d2[cnt];
	}
	for(int i = 0;i < n;i++){
		if(rev[p[i]]) x[i] = 3-x[i];
		if(x[i]==2) putchar('2');
		else if(n1) {
			putchar('1');
			--n1;
		}else putchar('3');
	}
	puts("");
	return 0;
}
