/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 18 Jul 2020 05:46:12 PM CST
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
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        ll x, y, z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x!=y&&x!=z&&y!=z) printf("NO\n");
        else if(x==y&&x<z) printf("NO\n");
        else if(x==z&&z<y) printf("NO\n");
        else if(y==z&&z<x) printf("NO\n");
        else{
            printf("YES\n");
            if(x==y) printf("%lld %lld %lld\n",x,z,z);
            else if(x==z) printf("%lld %lld %lld\n",y,x,y);
            else if(y==z) printf("%lld %lld %lld\n",x,x,y);
        }
    }
    return 0;
}
