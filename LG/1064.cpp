/************************************************************
	> File Name: 1064.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 07 May 2020 06:45:48 PM CST
************************************************************/

#include <cstdio>
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
int n, m;
int dp[5000010],f[5000010];
struct node{
	int v,p,q;
}a[1010];
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);
		a[i].p *= a[i].v;
	}
	for(int i = 1;i <= m;i++)
		if(!a[i].q){
			for(int j = 1;j < a[i].v;j++) f[j] = 0;
			for(int j = a[i].v;j <= n;j++) f[j] = dp[j-a[i].v] + a[i].p;
			for(int j = 1;j <= m;j++)
				if(a[j].q==i)
					for(int k = n;k >= a[i].v+a[j].v;k--)
						f[k] = max(f[k],f[k-a[j].v]+a[j].p);
			for(int j = a[i].v;j <= n;j++) dp[j] = max(dp[j],f[j]);
		}
	printf("%d\n",dp[n]);
	return 0;
}
