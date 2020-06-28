/************************************************************
	> File Name: sbag.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 11:43:47 AM CST
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
const int N = 1e5+10;
int V,n;
int dp[N],a[N];
signed main(void){
    while(~scanf("%d%d",&V,&n)){
        memset(dp,0,sizeof dp);
        for(int i = 1;i <= n;++i) scanf("%d",a+i);
        for(int i = 1;i <= n;++i)
            for(int j = V;j >= a[i];--j)
                dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
        printf("%s\n",dp[V]==V?"YES":"NO");
    }
    return 0;
}
