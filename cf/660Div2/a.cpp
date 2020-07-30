/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 30 Jul 2020 10:34:05 PM CST
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
signed main(void){
    int T;
    for(scanf("%d",&T);T--;){
        int n;
        scanf("%d",&n);
        if(n < 31) printf("NO\n");
        else{
            printf("YES\n");
            if(n==36) printf("6 10 15 5\n");
            else if(n==40) printf("6 10 15 9\n");
            else if(n==44) printf("6 10 15 13\n");
            else printf("6 10 14 %d\n",n-6-10-14);
        }
    }
    return 0;
}
