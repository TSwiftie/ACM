/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 08 Jun 2020 08:27:03 AM CST
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
const int N = 55;
int r[55],c[55];
signed main(void){
	int t, n, m;
	for(scanf("%d",&t);t--;){
		scanf("%d%d",&n,&m);
		for(int i = 1,x;i <= n;++i){
			for(int j = 1;j <= m;++j){
				scanf("%d",&x);
				if(x) r[i] = c[j] = 1;
			}
		}
		int aa = 0,bb = 0;
		for(int i = 1;i <= n;++i) aa += !r[i];
		for(int i = 1;i <= m;++i) bb += !c[i];
		int ans = min(aa,bb);
		printf("%s\n",ans&1?"Ashish":"Vivek");
		memset(r,0,sizeof r);
		memset(c,0,sizeof c);
	}
	return 0;
}
