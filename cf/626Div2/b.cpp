/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 31 Mar 2020 11:10:48 AM CST
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
vll gao(vi a){
	int n = SZ(a);
	vll res(n+1);
	int i = 0;
	while(i < n){
		if(!a[i]){
			i++;
			continue;
		}
		int j = i;
		while(j < n && a[j]==1) j++;
		for(int len = 1;len <= j-i;len++)
			res[len] += (j-i-len+1);
		i = j;
	}
	return res;
}
signed main(void){
	IOS;
	int n, m;
	ll k;
	cin >> n >> m >> k;
	vi a(n),b(m);
	for(int &x : a) cin >> x;
	for(int &x : b) cin >> x;
	ll ans = 0;
	vll ga = gao(a),gb = gao(b);
	for(int i = 1;i < SZ(ga);i++)
		if(k%i==0 && k/i <= m)
			ans += ga[i] * gb[k/i];
	cout << ans << endl;
	return 0;
}
