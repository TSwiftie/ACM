/************************************************************
	> File Name: e1.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 29 Jun 2020 08:09:10 AM CST
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
vi ra,ab,ba;
signed main(void){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i = 1,t,a,b;i <= n;++i){
        scanf("%d%d%d",&t,&a,&b);
        if(a&&b) ra.push_back(t);
        else if(a) ab.push_back(t);
        else if(b) ba.push_back(t);
    }
    sort(all(ab));
    sort(all(ba));
    for(int i = 0;i < min(SZ(ab),SZ(ba));++i)
        ra.push_back(ab[i]+ba[i]);
    if(SZ(ra) < k){
        printf("-1\n");
        return 0;
    }
    sort(all(ra));
    ll ans = 0;
    for(int i = 0;i < k;++i) ans += ra[i];
    printf("%lld\n",ans);
    return 0;
}
