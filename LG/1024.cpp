/************************************************************
	> File Name: 1024.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 10时42分53秒
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
double a, b, c, d;
double calc(double x){
    return a*x*x*x + b*x*x + c*x + d;
}
signed main(void){
    double l, r, m, x1, x2;
    int s = 0;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    for(int i = -100;i < 100;++i){
        l = i,r = i+1;
        x1 = calc(l),x2 = calc(r);
        if(!x1){
            printf("%.2lf ",l);
            ++s;
        }
        if(x1*x2 < 0){
            while(r - l >= 0.001){
                m = (l+r)/2;
                if(calc(m)*calc(r) <= 0) l = m;
                else r = m;
            }
            printf("%.2lf ",r);
            ++s;
        }
        if(s==3) break;
    }
    return 0;
}
