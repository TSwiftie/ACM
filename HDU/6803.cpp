/************************************************************
	> File Name: 6803.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 30 Jul 2020 08:33:34 PM CST
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
        int best = 1e9,cnt = 0;
        for(int i = 0;i < n;++i){
            int a, d;
            scanf("%d%d",&a,&d);
            int t = ((100 + a - 1) / a - 1) * d;
            if(t < best){
                best = t;
                cnt = 1;
            }else if(t==best) ++cnt;
        }
        double p = 1 - 0.5 * cnt / n;
        printf("%.20lf\n",p);
    }
    return 0;
}
