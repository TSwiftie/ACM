/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 22 Jun 2020 10:12:16 AM CST
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
mt19937 rnd(time(0));
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
const int N = 1e6+10;
char ch[N],sh[N];
int n,a[N];
int get(int x){
	int cur = 0,mx = 0;
	for(int i = 1;i <= n;++i){
		cur += x * a[i];
		mx = max(mx, cur);
		if(cur < 0) cur = 0;
	}
	return mx;
}
signed main(void){
	scanf("%d%s%s",&n,ch+1,sh+1);
	int sum = 0;
	for(int i = 1;i <= n;++i){
		if(ch[i]!=sh[i]){
			if(ch[i]=='1') a[i] = -1;
			else a[i] = 1;
		}
		sum += a[i];
	}
	if(sum!=0){
		printf("-1\n");
		return 0;
	}
	int ans = max(get(1),get(-1));
	printf("%d\n",ans);
	return 0;
}
