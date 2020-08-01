/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 01 Aug 2020 01:29:32 PM CST
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
const int N = 2e5+10;
int n,a[N],b[N];
vi G[N];
signed main(void){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i) scanf("%d",a+i);
    for(int i = 1;i <= n;++i){
        scanf("%d",b+i);
        if(b[i]!=-1){
            G[i].push_back(b[i]);
        }
    }
    return 0;
}
