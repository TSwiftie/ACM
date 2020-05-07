/************************************************************
	> File Name: 1833.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 07 May 2020 02:10:47 PM CST
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
int nx,ny,ex,ey,n,dp[1010];
int a[10005],b[10005],c[10005];
int tp,co[1000005],v[1000005];
inline void pre(){
	for(int i = 1;i <= n;i++){
		int t = 1;
		while(c[i]){
			co[++tp] = t*a[i];
			v[tp] = t*b[i];
			c[i] -= t; t <<= 1;
			if(c[i] < t){
				co[++tp] = a[i]*c[i];
				v[tp] = b[i]*c[i];
				break;
			}
		}
	}
}
signed main(void){
	scanf("%d:%d%d:%d%d",&nx,&ny,&ex,&ey,&n);
	int t = (ex*60+ey)-(nx*60+ny);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);
		if(!c[i]) c[i] = 999999;
	}
	pre();
	for(int i = 1;i <= tp;i++)
		for(int j = t;j >= co[i];j--)
			dp[j] = max(dp[j],dp[j-co[i]]+v[i]);
	printf("%d\n",dp[t]);
	return 0;
}
