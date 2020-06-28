/************************************************************
	> File Name: its.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 10:04:24 AM CST
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
int n,sum;
int dp[205][100005],a[205],b[205];
signed main(void){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) scanf("%d",a+i);
    for(int i = 1;i <= n;++i) scanf("%d",b+i);
    for(int i = 1;i <= n;++i){
        sum += a[i];
        for(int j = 0;j <= sum;++j){
            dp[i][j] = dp[i-1][j] + b[i];
            if(j >= a[i]) dp[i][j] = min(dp[i][j],dp[i-1][j-a[i]]);
        }
    }
    int ans = INF;
    for(int i = 0;i <= sum;++i) ans = min(ans,max(dp[n][i],i));
    printf("%d\n",ans);
    return 0;
}
