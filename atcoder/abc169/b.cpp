/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 08:04:00 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int unsigned long long
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
const int Max = 1e18;
signed main(void){
	int n;
	cin >> n;
	int ans = 1;
	bool mark = false,m1 = false;
	for(int i = 1,u;i <= n;++i){
		cin >> u;
		if(mark) continue;
		if(u==0){
			ans = 0;
			mark = true;
		}
		ans *= u;
		if(ans > Max) m1 = true;
	}
	if(m1) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
