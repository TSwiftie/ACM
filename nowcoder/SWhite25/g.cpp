/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 09:05:14 AM CST
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
int a;
ld b, c;
ld Bin(ld l,ld r){
	if(r-l <= EPS) return l;
	ld mid = (r+l)/2;
	ld res = 1;
	for(int i = 0;i < a;i++) res *= mid;
	res += b*log(mid);
	if(res < c) return Bin(mid,r);
	return Bin(l,mid);
}
signed main(void){
	cin >> a >> b >> c;
	cout << fixed << setprecision(7) << Bin(1,c) << endl;
	return 0;
}
