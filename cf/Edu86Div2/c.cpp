/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 29 Apr 2020 10:48:07 AM CST
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
LL t,n,a,b,q,lcm,s,r,l;
LL solve(LL l){
	return (l/lcm)*b+min(l%lcm,b-1);
}
signed main(void){
	for(cin >> t;t--;){
		cin >> a >> b >> q;
		if(a > b) swap(a,b);
		lcm = a/__gcd(a,b)*b;
		for(int i = 1;i <= q;i++){
			cin >> l >> r;
			l--;
			cout << r-l-solve(r)+solve(l);
			if(i==q) cout << endl;
			else cout << " ";
		}
	}
	return 0;
}
