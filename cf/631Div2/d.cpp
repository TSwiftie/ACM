/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 05 Apr 2020 01:07:48 PM CST
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
void solve(){
	int d, m;
	scanf("%d%d",&d,&m);
	ll ans = 1;
	for(int i = 0;i < 30;i++){
		if(d < (1<<i)) break;
		ans = ans * (min((1<<(i+1))-1,d)-(1<<i)+2)%m;
	}
	ans--;
	if(ans < 0) ans += m;
	printf("%lld\n",ans);
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;) solve();
	return 0;
}
