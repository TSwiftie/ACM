/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 22 Jun 2020 10:55:56 AM CST
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
int a[60],b[2];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;++i) scanf("%d",a+i),++b[a[i]%2];
		sort(a,a+n);
		int cnt = 0 ;
		for(int i = 1;i < n;++i)
			if(a[i]-a[i-1]==1)
				++cnt,++i;
		if(cnt >= b[0]%2) printf("YES\n");
		else printf("NO\n");
		b[0] = b[1] = 0;
	}
	return 0;
}
