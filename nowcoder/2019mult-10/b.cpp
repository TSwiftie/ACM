/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 15时53分20秒
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
const ll N = 510,Max = 1e12+10;
string s1 = "COFFEE";
string s2 = "CHICKEN";
ll dp[N];
char solve(int n,ll k){
    if(n==1) return s1[k-1];
    if(n==2) return s2[k-1];
    if(k <= dp[n-2]) return solve(n-2,k);
    else return solve(n-1,k-dp[n-2]);
}
signed main(void){
    IOS;
    dp[1] = 6;
    dp[2] = 7;
    for(int i = 3;i <= 500;++i){
        dp[i] = dp[i-2] + dp[i-1];
        dp[i] = min(dp[i],Max);
    }
    ll t, n, k;
    for(cin >> t;t--;){
        cin >> n >> k;
        for(ll i = k;i <= k+9 &&i <= dp[n];++i)
            cout << solve(n,i);
        cout << endl;
    }
    return 0;
}
