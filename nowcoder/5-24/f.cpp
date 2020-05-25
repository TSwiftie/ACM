/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 25 May 2020 05:09:47 PM CST
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
pll p[N];
signed main(void){
	IOS;
	int n;
	cin >> n;
	set<ll>s;
	for(int i = 0;i < n;i++){
		cin >> p[i].first >> p[i].second;
		s.insert(p[i].second);
		s.insert(p[i].second+1);
	}
	for(int i = 0;i < n;i++){
		if(p[i].first==1) s.erase(p[i].second);
		else if(p[i].first==2) s.insert(p[i].second);
		else cout << *s.lower_bound(p[i].second) << endl;
	}
	return 0;
}
