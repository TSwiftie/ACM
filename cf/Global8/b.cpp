/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 19 Jun 2020 09:38:33 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
string s = "codeforces";
signed main(void){
	IOS;
	int n;
	cin >> n;
	int x = 1,m = 1,y = 0;
	while(pow(x+1,10) < n) ++x;
	for(int i = 0;i < 10;++i) m*=x;
	while(m < n) m = m/x*(x+1),++y;
	for(int i = 0;i < 10;++i){
		for(int j = 1;j <= x;++j) cout << s[i];
		if(i < y) cout << s[i];
	}
	cout << endl;
	return 0;
}
