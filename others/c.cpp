/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 21时25分08秒
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
int a[N], n, k;
bool check(int x){
    int cnt = 0;
    for(int i = 1;i <= n;++i) if(a[i] > x) cnt += ceil(1.0*(a[i]-x)/(k-1));
    return cnt <= x;
}
signed main(void){
    scanf("%d%d",&n,&k);
    int l = 0,r = 0;
    for(int i = 1;i <= n;++i){ scanf("%d",a+i);r = max(r,a[i]); }
    while(l < r){
        int mid =(l+r)>>1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    printf("%d\n",l);
    return 0;
}
