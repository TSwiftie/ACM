/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 02:11:36 PM CST
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
double judge(int x){
    if(x >= 95 && x <= 100) return 4.3;
    else if(x >= 90 && x <= 94) return 4.0;
    else if(x >= 85 && x <= 89) return 3.7;
    else if(x >= 80 && x <= 84) return 3.3;
    else if(x >= 75 && x <= 79) return 3.0;
    else if(x >= 70 && x <= 74) return 2.7;
    else if(x >= 67 && x <= 69) return 2.3;
    else if(x >= 65 && x <= 66) return 2.0;
    else if(x >= 62 && x <= 64) return 1.7;
    else if(x >= 60 && x <= 61) return 1.0;
    else return 0;
}
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        int x;
        scanf("%d",&x);
        double ans = 0;
        for(int a = 60;a <= min(100,x);++a)
        {
            double tmp = 0;
            tmp += judge(a);
            ans = max(ans,tmp);
            for(int b = 60;b <= min(x-a,100);++b)
            {
                tmp += judge(b);
                ans = max(ans,tmp);
                for(int c = 60;c <= min(x-a-b,100);++c)
                {
                    tmp += judge(c);
                    ans = max(ans,tmp);
                    for(int d = 60;d <= min(x-a-b-c,100);++d)
                    {
                        tmp += judge(d);
                        ans = max(ans,tmp);
                        tmp -= judge(d);
                    }
                    tmp -= judge(c);
                }
                tmp -= judge(b);
            }
            tmp -= judge(a);
        }
        printf("%.1lf\n",ans);
    }
    return 0;
}
