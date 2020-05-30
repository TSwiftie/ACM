/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 30 May 2020 01:54:00 PM CST
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
inline ll ksm(ll a,ll b,ll p){
	ll res = 1;
	while(b){
		if(b&1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
signed main(void){
	ll a, b, p, x;
	cin >> a >> b >> p >> x;
	ll ans = 0;
	for(ll i = 1;i < p;i++){
		if(i==p-1)
		if((i%p * ksm(a,i,p))%p==b) ans++;
	}
	cout << ans*(x/p) << endl;
	return 0;
}
