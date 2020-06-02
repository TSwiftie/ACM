/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 02 Jun 2020 09:51:43 AM CST
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
const int N = 1e3+10;
int n, a[N], c[N];
inline int ksm(int a,int b){
	int res = 1;
	while(b){
		if(b&1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
signed main(void){
	IOS;
	int inv2 = ksm(2,p-2);
	while(cin >> n){
		for(int i = 1;i <= n;++i) cin >> a[i];
		for(int i = 1;i <= n;++i){
			c[i] = 1;
			for(int j = 1;j <= n;++j){
				if(i==j) continue;
				c[i] = c[i]*((a[j]*a[j]%p-a[i]*a[i]%p)%p+p)%p;
			}
			c[i] = ksm(c[i],p-2);
			c[i] = c[i]*ksm(a[i],p-2)%p;
			c[i] = c[i] * inv2 % p;
		}
		int ans = 0;
		for(int i = 1;i <= n;++i) ans = ((ans + c[i])%p + p) % p;
		cout << ans << endl;
	}
	return 0;
}
