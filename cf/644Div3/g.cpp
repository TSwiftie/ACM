/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 26 May 2020 07:53:03 PM CST
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
signed main(void){
	int t;
	for(cin >> t;t--;){
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		if(n*a!=m*b){
			cout << "NO" << endl;
			continue;
		}
		int e = 0;
		cout << "YES" << endl;
		for(int i = 0;i < n;i++){
			string s(m,'0');
			for(int j = 0;j < a;j++)
				s[(j+e)%m] = '1';
			cout << s << endl;
			e += a;
		}
	}
	return 0;
}
