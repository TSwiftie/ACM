/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 08 Aug 2020 05:52:13 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e5+10;
int n, k, z, a[N], dp[N][10];
signed main(void){
    int _t;
    for(scanf("%d",&_t);_t--;){
        scanf("%d%d%d",&n,&k,&z);
        for(int i = 1;i <= n;++i) scanf("%d",a+i);
        int ans = 0;
        for(int i = 0;i <= z;++i){
            for(int j = 1;j <= n;++j){
                dp[j][i] = max(dp[j-1][i] + a[j], i&&j<n?dp[j+1][i-1]+a[j]:0);
                if(j-1+(i<<1)==k) ans = max(ans,dp[j][i]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
