/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 24 Jun 2020 09:52:10 AM CST
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
mt19937 rnd(time(0));
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
int t, n, k, a[N], w[N];
signed main(void){
	IOS;
	for(cin >> t;t--;){
		cin >> n >> k;
		for(int i = 0;i < n;++i) cin >> a[i];
		for(int i = 0;i < k;++i) cin >> w[i],w[i]--;
		sort(a,a+n,greater<int>());
		sort(w,w+k);
		int s = accumulate(a,a+k,0LL);
		for(int i = 0,j = k-1;i < k;++i){
			if(!w[i]) s += a[i];
			else j += w[i], s += a[j];
		}
		cout << s << endl;
	}
	return 0;
}
