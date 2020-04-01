/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 09:52:10 AM CST
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
string s;
signed main(void){
	IOS;
	int t,n,k;
	for(cin >> t;t--;){
		cin >> n >> k >> s;
		int cnt = n/k,ans = 0;
		for(int l = 0,r = k-1;l <= r;l++,r--){
			int Min = INF;
			for(int ap = 'a';ap <= 'z';ap++){
				int tot = 0;
				for(int c = 0;c < cnt;c++){
					if(s[l+c*k]!=ap) tot++;
					if(l!=r)
						if(s[r+c*k]!=ap) tot++;
				}
				Min = min(Min,tot);
			}
			ans += Min;
		}
		cout << ans << endl;
	}
	return 0;
}
