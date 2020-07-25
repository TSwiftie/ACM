/************************************************************
	> File Name: 1006.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 25 Jul 2020 09:18:24 AM CST
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
const int N = 3e6+10;
int T;ull A, B, C, f[N];
inline ull read(){
    int n, x;ull res = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d",&x);
        if(x) res += f[i];
    }
    return res;
}
signed main(void){
    f[1] = 1,f[2] = 2;
    for(int i = 3;i < N ;++i) f[i] = f[i-1] + f[i-2];
    for(scanf("%d",&T);T--;){
        A = read();
        B = read();
        C = read();
        A *= B;
        int i;
        for(i = 1;C + f[i] != A;++i);
        printf("%d\n",i);
    }
    return 0;
}
