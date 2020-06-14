/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 14 Jun 2020 09:33:27 AM CST
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
	int t;
	for(scanf("%d",&t);t--;){
		int n, x, sum = 0,l = -1,r;
		scanf("%d%d",&n,&x);
		for(int i = 1,a;i <= n;++i){
			scanf("%d",&a);
			if(a%x){
				if(l==-1) l = i;
				r = i;
			}
			sum += a;
		}
		if(sum%x) printf("%d\n",n);
		else if(l==-1) printf("-1\n");
		else printf("%d\n",n-min(l,n-r+1));
	}
	return 0;
}
