/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 05:59:34 PM CST
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
signed main(void){
	IOS;
	int t;
	for(cin >> t;t--;){
		string s;
		cin >> s;
		bool mark = false;
		for(int i = 0;i < SZ(s);i++){
			if(i%2==0&&s[i]!='m'){
				mark = true;
				break;
			}
			if(i&1&&s[i]!='q'){
				mark = true;
				break;
			}
		}
		if(mark||SZ(s)&1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
