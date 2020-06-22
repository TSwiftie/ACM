/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 22 Jun 2020 09:52:31 AM CST
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
mt19937 rnd(time(0));
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
const int N = 2e5+10;
int n, k;
int a[N];
bool check(int x,int cur){
	int ans = 0;
	for(int i = 1;i <= n;++i){
		if(!cur){
			++ans;
			cur ^= 1;
		}else{
			if(a[i] <= x){
				++ans;
				cur ^= 1;
			}
		}
	}
	return ans >= k;
}
signed main(void){
	IOS;
	cin >> n >> k;
	for(int i = 1;i <= n;++i) cin >> a[i];
	int l = 1,r = 1e9;
	while(l < r){
		int mid = (l+r)>>1;
		if(check(mid,0) || check(mid,1)) r = mid;
		else l = mid+1;
	}
	cout << l << endl;
	return 0;
}
