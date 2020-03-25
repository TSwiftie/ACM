/************************************************************
	> File Name: 1089.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 25 Mar 2020 10:58:31 PM CST
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
bool calc(int x){
	if(x%11==0) return true;
	while(x){
		if(x%100==11) return true;
		x /= 10;
	}
	return false;
}
signed main(void){
	int ans,l,r;
	while(~scanf("%d%d",&l,&r)){
		ans = 0;
		while(l <= r) ans += calc(l++);
		printf("%d\r\n",ans);
	}
	return 0;
}
