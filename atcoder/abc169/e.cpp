/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 08:38:21 PM CST
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
const int N = 2e5+10;
int a[N],b[N],n;
int gcd1(int a,int b){
	return b?gcd1(b,a%b):a;
}
int mul(int a,int b,int p){
	int res = 0;
	while(b){
		if(b&1) res = (res + a) % p;
		a = (a+a)%p;
		b >>= 1;
	}
	return b;
}
int ksm(int a,int b,int p){
	int res = 1;
	while(b){
		if(b&1) res = a * res % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
int ksm1(int a,int b,int p){
	int res = 1;
	while(b){
		if(b&1) res = a * res % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
int ksm2(int a,int b,int p){
	int res = 1;
	while(b){
		if(b&1) res = a * res % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
int ksm3(int a,int b,int p){
	int res = 1;
	while(b){
		if(b&1) res = a * res % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
signed main(void){
	IOS;
	cin >> n;
	for(int i = 0;i < n;++i) cin >> a[i] >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	if(n&1) cout << b[n/2]-a[n/2]+1 << endl;
	else cout << b[(n-1)/2]+b[(n+1)/2]-a[(n-1)/2]-a[(n+1)/2]+1 << endl;
	return 0;
}
