/************************************************************
	> File Name: soldiers1.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 06:10:22 PM CST
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
const int N = 1e4+10;
int x[N],y[N],n,ans;
signed main(void){
    scanf("%d",&n);
    for(int i = 0;i < n;++i) scanf("%d%d",x+i,y+i);
    sort(x,x+n);
    sort(y,y+n);
    for(int i = 0;i < n;++i) x[i] -= i;
    sort(x,x+n);
    for(int i = 0;i < n;++i){
        ans += abs(x[i]-x[n/2]);
        ans += abs(y[i]-y[n/2]);
    }
    printf("%d\n",ans);
    return 0;
}
