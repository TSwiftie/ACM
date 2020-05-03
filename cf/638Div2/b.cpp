/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 10:19:50 AM CST
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
void solve(){
	int N,K;
	cin >> N >> K;
	set<int>s;
	for(int i = 0,x;i < N;i++){
		cin >> x;
		s.insert(x);
	}
	if(SZ(s) > K){
		cout << -1 << endl;
		return ;
	}
	cout << N*K << endl;
	for(int i = 0;i < N;i++){
		for(int b : s)
			cout << b << ' ';
		for(int j = 0;j < K-SZ(s);j++)
			cout << 1 << ' ';
	}
	cout << endl;
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;)
		solve();
	return 0;
}
