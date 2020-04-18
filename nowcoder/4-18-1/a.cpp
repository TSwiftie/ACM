/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 18 Apr 2020 06:43:06 PM CST
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
signed main(void){
	int a[4];
	for(int i = 0;i < 4;i++)
		scanf("%d",a+i);
	sort(a,a+4);
	printf("%d\n",abs(a[0]+a[3]-a[1]-a[2]));
	return 0;
}
