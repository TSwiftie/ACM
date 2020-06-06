/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 06 Jun 2020 01:37:23 PM CST
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
const int N = 1e5+10;
int t[N];
signed main(void){
	int T,n;
	for(cin >> T;T--;){
		cin >> n;
		double ans = 0,sum = 0;
		for(int i = 1;i <= n;++i)
			cin >> t[i];
		sort(t+1,t+1+n);
		for(int i = 1;i < n;++i){
			sum += t[i];
			ans += sum;
		}
		cout << fixed << setprecision(2) << ans/n << endl;
	}
	return 0;
}
