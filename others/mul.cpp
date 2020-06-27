/************************************************************
	> File Name: mul.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 27 Jun 2020 10:51:28 AM CST
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
mt19937 rnd(time(0));
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
const int N = 200;
int dp[N],n,m;
int t[N],c[N];
void ZeroOne(int cost,int val){
    for(int i = m;i >= cost;--i)
        dp[i] = min(dp[i],dp[i-cost]+val);
}
void Complete(int cost,int val){
    for(int i = cost;i <= m;++i)
        dp[i] = min(dp[i],dp[i-cost]+val);
}
void Mult(int cost,int val,int amount){
    if(cost*amount >= m) Complete(cost,val);
    else{
        int k = 1;
        while(k < amount){
            ZeroOne(cost*k,val*k);
            amount -= k;
            k <<= 1;
        }
        ZeroOne(cost*amount,val*amount);
    }
}
signed main(void){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i)
        scanf("%d%d",t+i,c+i);
    scanf("%d",&m);
    memset(dp,INF,sizeof dp);
    dp[0] = 0;
    for(int i = 1;i <= n;++i)
        Mult(t[i],1,c[i]);
    printf("%d\n",dp[m]==INF?-1:dp[m]);
    return 0;
}
