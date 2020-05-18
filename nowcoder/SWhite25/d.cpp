/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 05:42:19 PM CST
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
const ll p = 1e9+7;
const int N = 1e5+10;
ll ksm(ll a,ll b){
	ll res = 1;
	while(b){
		if(b&1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
ll a[N],b[N];
signed main(void){
	IOS;
	int n;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) cin >> b[i];
	ll A = 1,B = 1;
	for(int i = 1;i <= n;i++){
		A = (A * (a[i]-b[i]))%p;
		B = (B * a[i])%p;
	}
	A = (B-A+p)%p;
	cout << A*ksm(B,p-2)%p << endl;
	return 0;
}
