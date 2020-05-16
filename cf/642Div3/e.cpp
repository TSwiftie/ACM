/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 16 May 2020 09:50:22 AM CST
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
int solve(string &s){
	int n = SZ(s);
	int al = count(all(s),'1');
	int ans = al;
	vi res(n);
	int pref = 0;
	for(int i = 0;i < n;i++){
		int cur = (s[i]=='1');
		pref += cur;
		res[i] = 1-cur;
		if(i > 0) res[i] += min(res[i-1],pref-cur);
		ans = min(ans,res[i]+al-pref);
	}
	return ans;
}
signed main(void){
	IOS;
	int t;
	for(cin >> t;t--;){
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		vector<string> val(k);
		int cnt = count(all(s),'1');
		for(int i = 0;i < n;i++)
			val[i%k] += s[i];
		int ans = 1e9;
		for(auto &it : val)
			ans = min(ans,int(solve(it)+(cnt-count(all(it),'1'))));
		cout << ans << endl;
	}
	return 0;
}
