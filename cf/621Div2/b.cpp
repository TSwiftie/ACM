/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 09:15:42 PM CST
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
const int N = 1e5+10;
set<int>s;
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, x, Max = 0;
		scanf("%d%d",&n,&x);
		for(int i = 1,a;i <= n;i++){
			scanf("%d",&a);
			s.insert(a);
			Max = max(Max,a);
		}
		if(s.count(x)) printf("1\n");
		else printf("%d\n",max(2,(x-1)/Max+1));
		s.clear();
	}
	return 0;
}
