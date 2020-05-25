/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 25 May 2020 11:10:58 AM CST
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
const int N = 105;
ll t, n, m, a[N];
bitset<60> b;
signed main(void){
	IOS;
	for(cin >> t;t--;){
		cin >> n >> m;
		ll k = (1LL<<m)-n,mid = (k-1)/2;
		for(ll i = 0;i < n;++i)
			cin >> b,a[i] = b.to_ullong();
		sort(a,a+n);
		for(ll i = 0;i < n;++i)
			if(a[i] <= mid) ++mid;
		b = mid;
		for(ll i = m-1;i >= 0;--i)
			cout << b[i];
		cout << endl;
	}
	return 0;
}
