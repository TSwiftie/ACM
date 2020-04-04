/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 05:14:49 PM CST
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
	int t;
	for(scanf("%d",&t);t--;){
		int a[3];
		scanf("%d%d%d",a,a+1,a+2);
		sort(a,a+3);
		int ans = 0;
		if(a[0]) ans++,a[0]--;
		if(a[1]) ans++,a[1]--;
		if(a[2]) ans++,a[2]--;
		if(a[0]&&a[2]) ans++,a[0]--,a[2]--;
		if(a[1]&&a[2]) ans++,a[1]--,a[2]--;
		if(a[0]&&a[1]) ans++,a[0]--,a[1]--;
		if(a[0]&&a[1]&&a[2]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
