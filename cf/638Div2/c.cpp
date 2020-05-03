/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 03 May 2020 03:45:49 PM CST
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
int t, n, k;
char c,s[100010];
signed main(void){
	for(scanf("%d",&t);t--;){
		scanf("%d%d%s",&n,&k,s);
		sort(s,s+n);
		printf("%c",s[k-1]);
		if(s[k-1]==s[0] && s[k]==s[n-1])
			for(int i = 0;i < (n-1)/k;i++)
				printf("%c",s[k]);
		else if(s[k-1]==s[0])
			for(int i = k;i < n;i++)
				printf("%c",s[i]);
		puts("");
	}
	return 0;
}
