/************************************************************
	> File Name: 1003.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 29 May 2020 09:05:20 PM CST
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
const int N = 1e5+10;
int a[N];
signed main(void){
	int t;
	scanf("%d",&t);
	for(int cas = 1;cas <= t;++cas){
		int n,st = 1,ed = 1,x = 1;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
			scanf("%d",a+i);
		int sum = a[1],maxn = a[1];
		for(int i = 2;i <= n;++i){
			if(sum + a[i] < a[i]) x = i,sum = a[i];
			else sum += a[i];
			if(sum > maxn) maxn = sum,st = x,ed = i;
		}
		printf("Case %d:\n",cas);
		printf("%d %d %d\n",maxn,st,ed);
		if(cas!=t) puts("");
	}
	return 0;
}
