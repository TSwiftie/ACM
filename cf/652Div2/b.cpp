/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 24 Jun 2020 09:14:52 AM CST
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
mt19937 rnd(time(0));
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
int t,n;
string str;
signed main(void){
	IOS;
	for(cin >> t;t--;){
		cin >> n >> str;
		int i,j;
		for(i = 0;i < n&&str[i]=='0';++i)
			cout << "0";
		string ans = "";
		for(j = n-1;j >= 0&&str[j]=='1';--j)
			ans += "1";
		if(j+1!=i) cout << "0";
		cout << ans << endl;
	}
	return 0;
}

//11001101
//10101
//1101
//01
