/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 08:38:32 AM CST
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
	int t;
	for(scanf("%d",&t);t--;){
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		b -= a;
		d -= c;
		ll x[3],y[3];
		for(int i = 0;i < 3;i++)
			scanf("%lld%lld",x+i,y+i);
		if(x[0]+b>=x[1]&&x[0]+b<=x[2]&&y[0]+d>=y[1]&&y[0]+d<=y[2]){
			if((x[0]+1<=x[2]&&x[0]+1>=x[1])||(x[0]-1<=x[2]&&x[0]-1)>=x[1])
				if((y[0]+1<=y[2]&&y[0]+1>=y[1])||(y[0]-1<=y[2]&&y[0]-1>=y[1]))
					printf("YES\n");
				else printf("NO\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
	return 0;
}
