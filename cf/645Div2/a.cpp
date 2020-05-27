/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 27 May 2020 09:44:02 AM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, m;
		scanf("%d%d",&n,&m);
		int a = (n/2)*m+(n%2)*ceil(1.0*m/2);
		int b = (m/2)*n+(m%2)*ceil(1.0*n/2);
		printf("%d\n",min(a,b));
	}
	return 0;
}
