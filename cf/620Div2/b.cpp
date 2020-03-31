/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 31 Mar 2020 06:55:28 PM CST
************************************************************/

#include <algorithm>
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
map<string,bool>mp;
string str[104];
bool judge(string s){
	int l = 0,r = SZ(s)-1;
	while(l < r){
		if(s[l]!=s[r]) return false;
		l++;r--;
	}
	return true;
}
signed main(void){
	IOS;
	int n,m;
	cin >> n >> m;
	string ans = "";
	for(int i = 1;i <= n;i++){
		cin >> str[i];
		if(ans==""&&judge(str[i]))
			ans = str[i];
		mp[str[i]] = true;
	}
	for(int i = 1;i <= n;i++){
		if(ans!=""&&judge(str[i])){
			mp[str[i]] = false;
			continue;
		}
		if(mp[str[i]]){
			string now = str[i];
			reverse(all(now));
			if(mp[now]){
				ans = str[i] + ans + now;
				mp[now] = false;
				mp[str[i]] = false;
			}
		}
	}
	int sz = SZ(ans);
	if(!sz) cout << 0 << endl;
	else cout << sz << endl << ans << endl;
	return 0;
}
