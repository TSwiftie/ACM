/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 23 Mar 2020 11:31:24 AM CST
************************************************************/

#include <iterator>
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 2e6+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
int pi[MAXN];
string pre(string s){
	int n = (int)s.size(),j = 0;
	for(int i = 1;i < n;i++){
		while(j && s[i]!=s[j]) j = pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i] = j;
	}
	return s.substr(0,j);
}
signed main(void){
	IOS;
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();
		int i = 0,j = n-1;
		while(i < j && s[i]==s[j]){
			i++;j--;
		}
		string mid = s.substr(i,j-i+1);
		string rev = mid;
		reverse(range(rev));
		string ans1 = pre(mid+'#'+rev);
		string ans2 = pre(rev+'#'+mid);
		cout << s.substr(0,i) << (ans1.size()>ans2.size()?ans1:ans2) << s.substr(j+1) << endl;
	}
	return 0;
}
