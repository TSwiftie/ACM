/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 05:07:22 PM CST
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
const int N = 102;
int a[N],b[N],n;
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		for(int i = 1;i <= n;i++)
			scanf("%d",b+i);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(int i = 1;i <= n;i++)
			printf("%d%c",a[i]," \n"[i==n]);
		for(int i = 1;i <= n;i++)
			printf("%d%c",b[i]," \n"[i==n]);
	}
	return 0;
}
