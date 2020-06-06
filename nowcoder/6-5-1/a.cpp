/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 06 Jun 2020 01:34:24 PM CST
************************************************************/
#include <cctype>
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
bool isOn = true;
string str;
signed main(void){
	cin >> str;
	int ans = 0;
	for(int i = 0;i < SZ(str);++i){
		if(isupper(str[i])&&!isOn) ++ans,isOn = true;
		if(islower(str[i])&&isOn) ++ans,isOn = false;
	}
	cout << ans << endl;
	return 0;
}
