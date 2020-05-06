/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 06 May 2020 09:33:13 AM CST
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
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
signed main(void){
	int n = read(),k = read();
	int tag = -1;
	for(int i = 1,x;i <= n;i++){
		x = read();
		if(x==1) tag = i;
	}
	int ans = INF;
	for(int l = max(1,tag-k+1);l <= tag;l++){
		int r = l+k-1;
		int a1 = ceil(1.0*(l-1)/(k-1));
		int a2 = ceil(1.0*(n-r)/(k-1));
		ans = min(ans,a1+a2+1);
	}
	printf("%d\n",ans);
	return 0;
}
