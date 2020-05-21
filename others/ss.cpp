/************************************************************
	> File Name: ss.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 21 May 2020 10:10:53 AM CST
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
double f(int n){
	if(n==1) return 1.0;
	else if(n&1) return f(n-1)+1;
	else return f(n-1)/2;
}
signed main(void){
	double ans = 0;
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= 2*n;i++){
		if(i&1) ans += 1;
		else ans /= 2;
	}
	ans = 0;
	for(int i = 1;i <= 2*n;i++){
		if(i<=n) ans += 1;
		else ans /= 2;
	}
	printf("%lf\n",ans);
	ans = 0;
	int count = 0;
	for(int i = 1;i < 10;i++){
		if(i <= 5){
			ans = pow(2,i);
			count++;
		}
		ans = count/ans;
	}
	printf("%lf\n",ans);
	return 0;
}
