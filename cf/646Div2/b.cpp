/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 10:59:13 PM CST
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
int t;
signed main(void){
	IOS;
	for(cin >> t;t--;){
		string str;
		cin >> str;
		int zero = 0,one = 0;
		for(int i = 0;i < SZ(str);++i){
			if(str[i]=='0') ++zero;
			else ++one;
		}
		int ans = INF;
		if(str[0]=='0') ans = min(ans,min(one,zero-1));
		if(str[0]=='1') ans = min(ans,min(zero,one-1));
		if(str[SZ(str)-1]=='0') ans = min(ans,min(one,zero-1));
		if(str[SZ(str)-1]=='1') ans = min(ans,min(zero,one-1));
		printf("%d\n",ans);
	}
	return 0;
}
