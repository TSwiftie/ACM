/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 02:58:43 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int unsigned long long
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
const int N = 1e7+10;
int f[N],s[N],tot;
signed main(void){
	IOS;
	f[1] = f[2] = 1;s[1] = 1;s[2] = 2;
	for(tot = 3;;++tot){
		f[tot] = f[tot-1] + f[tot-2];
		s[tot] = s[tot-1] + f[tot];
		if(s[tot] >= LONG_LONG_MAX || s[tot] <= 0) break;
	}
	--tot;
	int t;
	for(cin >> t;t--;){
		int a;
		cin >> a;
		int k = lower_bound(s+1,s+1+tot,a)-s;
		if(s[k]==a) cout << k << endl;
		else cout << k-1 << endl;
	}
	return 0;
}
