/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 14 Jun 2020 09:49:12 AM CST
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
int cnt[N*10];
set<int>s;
signed main(void){
	int n;
	scanf("%d",&n);
	bool mark = false;
	for(int i = 1;i <= n;++i){
		scanf("%d",a+i);
		++cnt[a[i]];
		if(i < a[i]) mark = true;
	}
	if(mark){
		printf("-1\n");
		return 0;
	}
	for(int i = 0;i <= 1e6;++i)
		if(!cnt[i]) s.insert(i);
	for(int i = 1;i <= n;++i){
		printf("%d%c",*(s.begin())," \n"[i==n]);
		s.erase(s.begin());
		if(!--cnt[a[i]]) s.insert(a[i]);
	}
	return 0;
}
