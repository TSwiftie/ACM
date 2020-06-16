/************************************************************
	> File Name: te.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 16 Jun 2020 01:30:05 PM CST
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
const int N = 1e5;
const int p = 1e9+7;
int fac[N+10];
int ksm(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
signed main(void){
	fac[0] = fac[1] = 1;
	for(int i = 2;i <= N;++i)
		fac[i] = fac[i-1] * i % p;
	int n;
	while(cin >> n){
		int ans;
		if(n&1) ans = (n-1)/2*n%p;
		else ans = n/2*(n-1)%p;
		cout << fac[n] * ans % p << endl;
	}
	return 0;
}
