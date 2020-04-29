/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 29 Apr 2020 10:24:40 AM CST
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
string s,t;
signed main(void){
	IOS;
	int T;
	for(cin >> T;T--;){
		cin >> t;
		int n = SZ(t);
		bool flag = true;
		for(int i = 0;i < n-1;i++)
			if(t[i]!=t[i+1]) flag = false;
		if(flag) cout << t << endl;
		else{
			s.clear();
			for(int i = 0;i < n;i++){
				s+='1';
				s+='0';
			}
			cout << s << endl;
		}
	}
	return 0;
}
