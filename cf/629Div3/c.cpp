/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 30 Mar 2020 05:20:26 PM CST
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
const int N = 5e4+10;
char ch[N],a[N],b[N];
signed main(void){
	int t,n;
	for(cin >> t;t--;){
		cin >> n;
		string a = "",b = "",s;
		cin >> s;
		bool mark = true;
		for(int i = 0;i < n;i++)
			if(mark){
				if(s[i]=='2') a+='1',b+='1';
				else if(s[i]=='0') a+='0',b+='0';
				else a += '1',b += '0', mark = false;
			}else a += '0',b += s[i];
		cout << a << endl << b << endl;
	}
	return 0;
}
