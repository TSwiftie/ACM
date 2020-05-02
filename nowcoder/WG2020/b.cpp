/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 02 May 2020 12:01:31 PM CST
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
const int N = 1e3+10;
int a[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n,Max = 0,Min = 60001;
		double sum = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d",a+i);
			sum += a[i];
			Max = max(Max,a[i]);
			Min = min(Min,a[i]);
		}
		sum /= n;
		double ans = 0;
		for(int i = 1;i <= n;i++)
			ans += (sum-a[i])*(sum-a[i]);
		printf("%d %.3lf\n",Max-Min,ans/n);
	}
	return 0;
}
