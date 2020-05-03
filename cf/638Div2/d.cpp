/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 03:51:15 PM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		vector<int> ans;
		for(int i = 1;i <= n;i <<= 1){
			ans.push_back(i);
			n = n-i;
		}
		if(n > 0){
			ans.push_back(n);
			sort(all(ans));
		}
		cout << SZ(ans)-1 << endl;
		for(int i = 1;i < SZ(ans);i++)
			cout << ans[i]-ans[i-1] << " ";
		cout << endl;
	}
	return 0;
}
