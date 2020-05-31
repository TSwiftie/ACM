/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 10:54:06 PM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n, x;
		scanf("%d%d",&n,&x);
		int odd = 0,even = 0;
		for(int i = 1,u;i <= n;++i){
			scanf("%d",&u);
			if(u&1) ++odd;
			else ++even;
		}
		bool mark = false;
		for(int i = 1;i <= odd;i+=2){
			if(i > x) break;
			if(x >= i && (x-i)>=0 && (x-i) <= even){
				mark = true;
				break;
			}
		}
		printf("%s\n",mark?"Yes":"No");
	}
	return 0;
}
