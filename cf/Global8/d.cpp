/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 19 Jun 2020 09:47:18 AM CST
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
int s[30];
signed main(void){
	int n,ans = 0;
	cin >> n;
	for(int i = 1,x;i <= n;++i){
		cin >> x;
		for(int j = 0;j < 30;++j)
			s[j] += (x>>j)&1;
	}
	while(true){
		int x = 0;
		for(int i = 0;i < 30;++i)
			if(s[i]) x += (1<<i),--s[i];
		if(!x) break;
		ans += 1LL*x*x;
	}
	cout << ans << endl;
	return 0;
}
