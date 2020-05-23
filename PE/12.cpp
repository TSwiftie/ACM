/************************************************************
	> File Name: 12.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 23 May 2020 10:30:01 PM CST
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
	ll n,tmp = 1;
	scanf("%lld",&n);
	while(true){
		ll cnt = 0,tri = tmp*(tmp+1)/2;
		for(ll i = 1;i*i <= tri;i++){
			if(tri%i==0)
				cnt += i*i==tri?1:2;
		}
		if(cnt >= n){
			printf("%lld\n",tri);
			break;
		}
		tmp++;
	}
	return 0;
}
