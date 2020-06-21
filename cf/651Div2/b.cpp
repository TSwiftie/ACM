/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 21 Jun 2020 06:39:29 PM CST
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
const int N = 1e3+10;
signed main(void){
	IOS;
	int t,n;
	for(cin >> t;t--;){
		cin >> n;
		vi v[2];
		for(int i = 1,a;i <= 2*n;++i){
			cin >> a;
			v[a%2].push_back(i);
		}
		int cnt = 0;
		for(int i = 0;i < 2 && cnt < n-1;++i)
			for(int j = 0;j+1 < SZ(v[i]) && cnt<n-1;j += 2){
				cout << v[i][j] << " " << v[i][j+1] << endl;
				++cnt;
			}
	}
	return 0;
}
