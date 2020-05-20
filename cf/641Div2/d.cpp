/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 20 May 2020 05:57:39 PM CST
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
int a[N],n,m;
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++)
			scanf("%d",a+i);
		int ans = 0;
		for(int i = 1;i <= n;i++) ans |= a[i]==m,ans |= ((i<n&&a[i]>=m&&a[i+1]>=m)||(i<n-1&&a[i]>=m&&a[i+2]>=m)?2:0);
		puts(ans==3||ans==1&&n==1?"yes":"no");
	}
	return 0;
}
