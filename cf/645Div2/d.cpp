/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 27 May 2020 11:06:29 AM CST
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
const int N = 4e5+10;
int n;
ll x, d[N];
signed main(void){
	IOS;
	cin >> n >> x;
	for(int i = 1;i <= n;++i) cin >> d[i],d[i+n] = i<n?d[i]:0;
	ll l = 2*n-1,sum = 0,ans = 0,now = 0;
	for(int i = 2*n-1;i >= n;--i){
		while(sum < x){
			now += d[l]*(d[l]+1)/2;
			sum += d[l--];
		}
		ans = max(ans,now-(sum-x)*(sum-x+1)/2);
		sum -= d[i];
		now -= d[i]*(d[i]+1)/2;
	}
	cout << ans << endl;
	return 0;
}
