/************************************************************
	> File Name: i.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 08:41:12 AM CST
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
const int N = 1e6+10;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch<='9'&&ch>='0';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
ll r[N],c[N];
signed main(void){
	IOS;
	ll n = read(),m = read(),x;
	vector<vll> a(n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			x = read();
			c[i] += x;
			r[j] += x;
			a[i].push_back(x);
		}
	}
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			cout << r[j]+c[i]-a[i][j];
			if(j==m-1) cout << endl;
			else cout << " ";
		}
	return 0;
}
