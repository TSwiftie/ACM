/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 08:46:13 AM CST
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
        ll l, r, m;
        scanf("%lld%lld%lld",&l,&r,&m);
        for(ll a = l;a <= r;++a){
            ll d = (m-l+r)%a+l-r;
            if(d > r-l || d > m-a) continue;
            ll c = d > 0 ? l : (l-d);
            ll b = c + d;
            printf("%lld %lld %lld\n",a,b,c);
            break;
        }
    }
    return 0;
}
