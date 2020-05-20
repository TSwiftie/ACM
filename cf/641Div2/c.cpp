/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 05:52:23 PM CST
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
int a[N],n;
signed main(void){
	IOS;
	cin >> n;
	for(int i = 1,v;i <= n;i++)
		cin >> v,a[v]++;
	ll ans = 1;
	for(int i = 2;i < N;i++){
		for(int j = 2*i;j < N;j+=i)
			a[i] += a[j];
		if(a[i] >= n-1) ans = ans/__gcd(1ll*i,ans)*i;
	}
	cout << ans << endl;
	return 0;
}
