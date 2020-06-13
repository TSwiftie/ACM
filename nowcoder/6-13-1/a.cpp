/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 13 Jun 2020 01:02:29 PM CST
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
const int N = 1e5+10;
const int p = 1e9+7;
char ch[N];
int suf[N];
signed main(void){
	int t;
	IOS;
	for(cin >> t;t--;){
		cin >> (ch+1);
		int n = strlen(ch+1),preSum = 0,ans = 0;
		suf[n] = 1;
		for(int i = n-1;i > 0;--i)
			suf[i] = suf[i+1]*10%p;
		for(int i = 1;i <= n;++i){
			int pre = preSum;
			if(i!=1) pre = (pre + 1) % p;
			if(ch[i]>='7') pre = (pre + 1) % p;
			if(ch[i]<'7'&&i!=1) pre = (pre - 1 + p) % p;
			ans = (ans + pre*suf[i]%p) % p;
			//cout << pre << " " << suf[i] << endl;
			preSum = (preSum*10%p + (ch[i]-'0')) % p;
		}
		cout << ans << endl;
	}
	return 0;
}
