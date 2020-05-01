/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 01 May 2020 04:20:08 PM CST
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
int t;
signed main(void){
	for(scanf("%d",&t);t--;){
		int n, m, num, x, cnt1 = 0,cnt2 = 1;
		scanf("%d%d",&n,&m);
		scanf("%d",&num);
		for(int i = 1;i < n;i++){
			scanf("%d",&x);
			if(x==num) cnt1++;
			if(x>=num) cnt2++;
		}
		if(m<=n-cnt1){
			printf("%d\n",cnt2-cnt1);
			continue;
		}
		m-=(n-cnt1);
		printf("%d\n",cnt2-cnt1+m);
	}
	return 0;
}
