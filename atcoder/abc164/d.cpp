/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 27 Apr 2020 07:24:27 PM CST
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
const int mod = 2019;
signed main(void){
	string s;
	cin >> s;
	vll d(SZ(s)+1);
	int ten = 1;
	for(int i = SZ(s)-1;i >= 0;i--){
		int a = (s[i]-'0') * ten % mod;
		d[i] = (d[i+1]+a)%mod;
		ten *= 10;
		ten %= mod;
	}
	vll cnt(SZ(s)+1);
	LL ans = 0;
	for(int i = SZ(s);i >= 0;i--){
		ans += cnt[d[i]];
		cnt[d[i]]++;
	}
	cout << ans << endl;
	return 0;
}
