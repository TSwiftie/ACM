/************************************************************
	> File Name: 1003.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 04 Aug 2020 02:50:44 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
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
const int N = 1e6+10;
int n, k, p[N], ans[N];
void change(int l,int r){
    int mid = (l+r)>>1;
}
void solve(){
    scanf("%d%d",&n,&k);
    int m = 2*n*(1<<k);
    for(int i = 0;i < m;++i) scanf("%d",p+i);
}
signed main(void){
    int T;
    for(scanf("%d",&T);T--;) solve();
    return 0;
}
