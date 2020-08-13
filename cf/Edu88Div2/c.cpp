/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Fri 29 May 2020 10:16:00 AM CST
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
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
        ll c, h, ti;
        scanf("%lld%lld%lld",&h,&c,&ti);
        if(h==ti) printf("1\n");
        else if(2*ti <= (h+c)) printf("2\n");
        else{
            int k = (ti-h)/(h+c-2*ti);
            if(fabs(1.0*((h+c-2*ti)*k+h-ti)/(2*k+1)) > fabs(1.0*((h+c-2*ti)*(k+1)+h-ti)/(2*k+3))) ++k;
            printf("%d\n",2*k+1);
        }
	}
	return 0;
}
