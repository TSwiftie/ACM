/************************************************************
	> File Name: 2761.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Tue 21 Apr 2020 08:54:45 PM CST
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
signed main(void){
	IOS;
	int t;
	for(cin >> t;t--;){
		int n, x;
		map<int,bool>vis;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> x;
			if(!vis[x]) vis[x] = true;
			else continue;
			if(i!=1) cout << " " << x;
			else cout << x;
		}
		cout << endl;
	}
	return 0;
}
