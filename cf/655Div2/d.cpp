/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月13日 星期一 16时35分32秒
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
const int N = 2e5+10;
int n, a[N];
signed main(void){
    scanf("%d",&n);
    for(int i = 0;i < n;++i) scanf("%d",a+i);
    ll ans = 0,cnt = 0;
    for(int i = 0;i < n;i += 2) cnt += a[i];
    int i = n-1;
    for(int cntt = 0;cntt < n;++cntt){
        ans = max(ans,cnt);
        cnt += a[(i+2)%n];
        cnt -= a[(i+1)%n];
        i = (i+2)%n;
    }
    printf("%lld\n",ans);
    return 0;
}
