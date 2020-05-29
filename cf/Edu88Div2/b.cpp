/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 29 May 2020 10:07:59 AM CST
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
char ch[105][1005];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, m, x, y;
		scanf("%d%d%d%d",&n,&m,&x,&y);
		for(int i = 1;i <= n;++i)
			scanf("%s",ch[i]+1);
		bool sta = false;
		int ans = 0;
		if(2*x > y) sta = true;
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= m;++j){
				if(ch[i][j]=='.'){
					if(sta && j+1 <= m && ch[i][j+1]=='.')
						ans += y,++j;
					else ans += x;
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}
