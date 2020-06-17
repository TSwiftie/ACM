/************************************************************
	> File Name: t6.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 08:23:52 PM CST
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
int cnt[1000006],a[N],Idx;
signed main(void){
	int n, q;
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;++i){
		scanf("%d",a+i);
		if(!cnt[a[i]]) ++Idx;
		++cnt[a[i]];
	}
	while(q--){
		int l, r;
		scanf("%d%d",&l,&r);
	}
	return 0;
}
