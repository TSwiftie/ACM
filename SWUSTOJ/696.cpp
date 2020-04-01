/************************************************************
	> File Name: 696.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 01:55:46 PM CST
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
const int N = 1e5+10;
int x[N],y[N];
signed main(void){
	IOS;
	int n, ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++)
		cin >> x[i] >> y[i];
	sort(x,x+n);
	sort(y,y+n);
	int mid = y[n/2];
	for(int i = 0;i < n;i++)
		ans += abs(y[i]-mid);
	for(int i = 0;i < n;i++) x[i]-=i;
	sort(x,x+n);
	mid = x[n/2];
	for(int i = 0;i < n;i++)
		ans += abs(x[i]-mid);
	cout << ans << endl;
	return 0;
}
