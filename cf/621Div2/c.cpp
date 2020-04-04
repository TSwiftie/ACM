/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 09:57:50 PM CST
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
ll a[26],b[26][26];
signed main(void){
	IOS;
	string s;
	cin >> s;
	for(int i = 0;i < SZ(s);i++){
		int c = s[i]-'a';
		for(int j = 0;j < 26;j++)
			b[j][c] += a[j];
		a[c]++;
	}
	ll ans = 0;
	for(int i = 0;i < 26;i++)
		ans = max(ans,a[i]);
	for(int i = 0;i < 26;i++)
		for(int j = 0;j < 26;j++)
			ans = max(ans,b[i][j]);
	cout << ans << endl;
	return 0;
}
