/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 04 Apr 2020 04:42:19 PM CST
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
		int a, b, c, d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int x[3],y[3],xx,yy;
		scanf("%d%d%d%d%d%d",x,y,x+1,y+1,x+2,y+2);
		xx = x[0],yy = y[0];
		x[0] += (b-a);y[0] += (d-c);
		if(x[0]>=x[1]&&x[0]<=x[2]&&y[0]>=y[1]&&y[0]<=y[2]&&(x[2]>x[1]||a+b==0)&&(y[2]>y[1]||c+d==0))
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
