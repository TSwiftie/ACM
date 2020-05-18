/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 08:36:31 AM CST
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
signed main(void){
	IOS;
	string str;
	stack<char>st;
	cin >> str;
	for(int i = 0;i < SZ(str);i++){
		if(st.empty()) st.push(str[i]);
		else if(st.top()==str[i]) st.pop();
		else st.push(str[i]);
	}
	string ans = "";
	while(!st.empty()){
		ans = st.top() + ans;
		st.pop();
	}
	if(SZ(ans)==0) cout << 0 << endl;
	else cout << ans << endl;
	return 0;
}
