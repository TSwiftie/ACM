/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 31 Mar 2020 10:22:18 AM CST
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
	int t,n;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		int ans = 0;
		for(int i = 1,x;i <= n;i++){
			scanf("%d",&x);
			if(x%2==0) ans = i;
		}
		if(ans) printf("1\n%d\n",ans);
		else puts(n==1?"-1":"2\n1 2");
	}
	return 0;
}
