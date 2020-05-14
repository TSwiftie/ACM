/************************************************************
	> File Name: 3758.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 14 May 2020 10:27:30 AM CST
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
const int mod = 2017;
struct Matrix{
	int a[31][31];
	inline Matrix operator * (const Matrix &rhs){
		Matrix ret;
		memset(&ret,0,sizeof ret);
		for(int i = 0;i <= 30;i++)
			for(int j = 0;j <= 30;j++)
				for(int k = 0;k <= 30;k++)
					(ret.a[i][j] += a[i][k]*rhs.a[k][j]%mod)%=mod;
		return ret;
	}
}mp;
Matrix ksm(Matrix &a,int b){
	Matrix ret;
	memset(&ret,0,sizeof ret);
	for(int i = 0;i <= 30;i++) ret.a[i][i] = 1;
	while(b){
		if(b&1) ret = ret * a;
		a = a * a;
		b >>= 1;
	}
	return ret;
}
int u, v, m, n, t;
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++){
		scanf("%d%d",&u,&v);
		mp.a[u][v] = mp.a[v][u] = 1;
	}
	for(int i = 0;i <= n;i++)
		mp.a[i][i] = 1;
	for(int i = 1;i <= n;i++) mp.a[i][0] = 1;
	int ans = 0;
	scanf("%d",&t);
	Matrix anss = ksm(mp,t);
	for(int i = 0;i <= n;i++) (ans += anss.a[1][i]) %= mod;
	printf("%d\n",ans);
	return 0;
}
