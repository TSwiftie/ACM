/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 01 May 2020 10:25:03 AM CST
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
LL f[50][270];
signed main(void){
	string s, t;
	int n;
	cin >> s >> t;
	cin >> n;
	for(int i = 0;i < SZ(s);i++)
		f[1][s[i]]++;
	for(int i = 0;i < SZ(t);i++)
		f[2][t[i]]++;
	for(int i = 3;i <= n;i++)
		for(int j = 0;j <= 266;j++)
			f[i][j] = f[i-1][j] + f[i-2][j];
	for(int i = 0;i <= 266;i++)
		if(f[n][i])
			cout << char(i) << ": " << f[n][i] << endl;
	return 0;
}
