/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 03:28:23 PM CST
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
const int p = 1e9+7;
const int N = 1e5+10;
int t, n, m, k;
int fac[N];
inline int ksm(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
inline int inv(int a){
	return ksm(a,p-2);
}
signed main(void){
	fac[0] = 1;
	for(int i = 1;i < N;i++)
		fac[i] = fac[i-1] * i % p;
	/*
	 * for(cin >> t;t--;){
	 *     cin >> n >> m >> k;
	 *     if(n-m < k) cout << 0 << endl;
	 *     else{
	 *         int re = n-m;
	 *     }
	 * }
	 */
	cout << 56 * inv(256) % p << endl;
	return 0;
}
