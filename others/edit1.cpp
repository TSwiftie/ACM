/************************************************************
	> File Name: edit1.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 06:12:20 PM CST
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
const int N = 1e3+10;
int dp[N][N];
string a,b;
signed main(void){
    cin >> a >> b;
    for(int i = 0;i <= SZ(a);++i) dp[i][0] = i;
    for(int i = 0;i <= SZ(b);++i) dp[0][i] = i;
    for(int i = 1;i <= SZ(a);++i)
        for(int j = 1;j <= SZ(b);++j){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1;
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
        }
    cout << dp[SZ(a)][SZ(b)] << endl;
    return 0;
}
