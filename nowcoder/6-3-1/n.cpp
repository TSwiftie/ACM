/************************************************************
	> File Name: n.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 05 Jun 2020 11:34:25 AM CST
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
const int N = 1e6+10;
const int p = 1e9+7;
int ans[N];
signed main(void){
	ans[1] = 2;
	ans[2] = 8;
	for(int i = 3;i < N;++i)
		ans[i] = (3*ans[i-1]%p + 2)%p;
	int t;
	for(cin >> t;t--;){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
	return 0;
}
