/************************************************************
	> File Name: t1.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 01 Jul 2020 05:55:32 PM CST
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
int pre[N],suf[N],n,a[N],ans = INF;
signed main(void){
    scanf("%d",&n);
    pre[0] = 0,suf[n+1] = 0;
    for(int i = 1;i <= n;++i){
        scanf("%d",a+i);
        pre[i] = pre[i-1] + a[i];
    }
    for(int i = n;i >= 1;--i)
        suf[i] = suf[i+1] + a[i];
    for(int i = 1;i < n;++i){
        ans = min(ans,abs(pre[i]-suf[i+1]));
    }
    printf("%d\n",ans);
    return 0;
}
