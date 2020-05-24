/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 02:15:40 PM CST
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
const int N = 1e3+10;
int a[N][N];
signed main(void){
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			scanf("%d",&a[i][j]);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			a[i][j] = -a[i][j];
			if(i==j) a[i][j] ++;
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			printf("%d%c",a[i][j]," \n"[j==n]);
	return 0;
}
