/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 30 May 2020 01:07:05 PM CST
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
const int N = 1003;
int n;
char ch[N][N],sh[N][N];
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;++i)
		scanf("%s",ch[i]+1);
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			sh[i][j] = ch[n-j+1][i];
	for(int i = 1;i <= n;++i)
		printf("%s\n",sh[i]+1);
	return 0;
}
