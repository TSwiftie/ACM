/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 17 May 2020 10:31:14 AM CST
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
int a[N],n,A,R,M;
ll check(int x){
	ll s1 = 0,s2 = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] > x) s1 += a[i]-x;
		else s2 += x-a[i];
	}
	if(s1 > s2) return (s1-s2)*R+s2*M;
	return (s2-s1)*A+s1*M;
}
signed main(void){
	scanf("%d%d%d%d",&n,&A,&R,&M);
	M = min(M,A+R);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	int l = 0,r = 1e9;
	while(r-l > 20){
		int m1 = l+(r-l)/3,m2 = l+(r-l)/3*2;
		if(check(m1) < check(m2)) r = m2;
		else l = m1;
	}
	ll ans = 1LL<<60LL;
	for(int i = l;i <= r;i++) ans = min(ans,check(i));
	printf("%lld\n",ans);
	return 0;
}
