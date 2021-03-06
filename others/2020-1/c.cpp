/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 03:28:38 PM CST
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
//mt19937 rnd(time(0));
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
int dp[1010][1010];
signed main(void){
    int t;
    for(int i = 1;i <= 1000;++i)
        for(int j = 1;j <= 1000;++j)
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + (__gcd(i,j)==1);
    for(scanf("%d",&t);t--;){
        int a, b;
        scanf("%d%d",&a,&b);
        printf("%d\n",dp[a][b]);
    }
    return 0;
}
