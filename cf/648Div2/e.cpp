/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 08 Jun 2020 02:03:16 PM CST
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
const int N = 505;
int a[N];
signed main(void){
	IOS;
	int n,ans = 0;
	cin >> n;
	for(int i = 1;i <= n;++i)
		cin >> a[i];
	if(n==1) cout << a[1] << endl;
	else if(n==2) cout << (a[1]|a[2]) << endl;
	else{
		int ans = 0;
		for(int i = 1;i <= n;++i)
			for(int j = i+1;j <= n;++j)
				for(int k = j+1;k <= n;++k)
					ans = max(ans,a[i]|a[j]|a[k]);
		cout << ans << endl;
	}
	return 0;
}
