/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 08 Jun 2020 11:39:16 AM CST
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
const int N = 505;
int a[N];
bool c[2];
signed main(void){
	IOS;
	int t;
	for(cin >> t;t--;){
		int n;
		cin >> n;
		vi aa,bb;
		c[0] = c[1] = 0;
		for(int i = 1;i <= n;++i) cin >> a[i];
		for(int i = 1,x;i <= n;++i) cin >> x,c[x] = 1;
		int i;
		for(i = 1;i < n;++i)
			if(a[i] > a[i+1]) break;
		printf("%s\n",c[0]&&c[1]||i==n?"Yes":"No");
	}
	return 0;
}
