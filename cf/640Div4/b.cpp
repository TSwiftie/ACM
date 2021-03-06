/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 10 May 2020 09:01:15 PM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		LL n, k;
		scanf("%lld%lld",&n,&k);
		if(k > n){
			printf("NO\n");
			continue;
		}
		if((n-(k-1))&1){
			printf("YES\n");
			for(int i = 1;i < k;i++) printf("1 ");
			printf("%lld\n",n-k+1);
		}else if((n-(k-1)*2)%2==0&&(n-(k-1)*2)>0){
			printf("YES\n");
			for(int i = 1;i < k;i++) printf("2 ");
			printf("%lld\n",n-(k-1)*2);
		}else printf("NO\n");
	}
	return 0;
}
