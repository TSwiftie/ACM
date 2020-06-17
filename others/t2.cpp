/************************************************************
	> File Name: te2.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 17 Jun 2020 06:09:48 PM CST
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
const int N = 5e3+10;
int Max = -1,Min = -1;
int a[N];
vector<int>ma,mi;
signed main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;++i){
		scanf("%d",a+i);
		if(Max==-1) Max = a[i];
		if(Min==-1) Min = a[i];
		if(a[i] > Max) Max = a[i];
		if(a[i] < Min) Min = a[i];
	}
	for(int i = 1;i <= n;++i){
		if(a[i]==Max) ma.push_back(i);
		if(a[i]==Min) mi.push_back(i);
	}
	int ans = n;
	for(int i : ma)
		for(int j : mi){
			int f = min(i,j),s = max(i,j);
			ans = min(ans,s-f+1);
		}
	printf("%d\n",ans);
	return 0;
}
