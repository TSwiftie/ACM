/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 18 May 2020 08:20:31 AM CST
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
const int N = 2e5+10;
int n, m;
int a[N],sum;
signed main(void){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n-m;i++){
		scanf("%d",a+i);
		sum += a[i];
	}
	double Min = sum + m;
	double Max = sum + 5*m;
	printf("%.5lf %.5lf\n",Min/n,Max/n);
	return 0;
}
