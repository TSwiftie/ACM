/************************************************************
	> File Name: 3.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 05 Apr 2020 02:01:03 PM CST
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
const int N = 104;
int e[N][N],n,a[N];
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			e[i][j] = i==j?0:INF;
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1,u,v;i < n;i++){
		scanf("%d%d",&u,&v);
		e[u][v] = e[v][u] = 1;
	}
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(e[i][j] > e[i][k]+e[k][j])
					e[i][j] = e[i][k] + e[k][j];
	int ans = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(a[i] < a[j])
				ans = max(ans,e[i][j]*a[j]);
	printf("%d\n",ans);
	return 0;
}
