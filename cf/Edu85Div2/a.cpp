/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 12 Apr 2020 08:50:47 PM CST
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
const int N = 102;
int p[N],c[N];
signed main(void){
	int t,n;
	for(scanf("%d",&t);t--;){
		scanf("%d",&n);
		p[0] = 0,c[0] = 0;
		bool mark = false;
		for(int i = 1;i <= n;i++){
			scanf("%d%d",p+i,c+i);
			if(p[i] < p[i-1] || c[i] < c[i-1]) mark = true;
			if(p[i]-p[i-1] < c[i]-c[i-1]) mark = true;
		}
		printf("%s\n",mark?"NO":"YES");
	}
	return 0;
}
