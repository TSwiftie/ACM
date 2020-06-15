/************************************************************
	> File Name: te.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 15 Jun 2020 02:55:10 PM CST
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
const int N = 5;
int a[N] = {1,2,3,4,5},b[N];
int trans[5][5] = {
	0,0,1,0,0,
	0,0,0,0,1,
	0,1,0,0,0,
	0,0,0,1,0,
	1,0,0,0,0
};
void mul(){
	for(int i = 0;i < 5;++i){
		int tmp = 0;
		for(int j = 0;j < 5;++j)
			tmp += trans[i][j] * a[j];
		b[i] = tmp;
	}
	for(int i = 0;i < 5;++i) a[i] = b[i];
}
void print(){
	for(int i = 0;i < 5;++i)
		printf("%d%c",a[i]," \n"[i==4]);
}
signed main(void){
	print();
	for(int i = 1;i <= 4;++i){
		mul();
		print();
	}
	return 0;
}
