/************************************************************
	> File Name: 1006.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Thu 23 Jul 2020 01:16:22 PM CST
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
const int N = 1e6+10;
int fib[N];
void init(){
    fib[1] = 1,fib[2] = 2;
    for(int i = 3;i < N;++i){
        fib[i] = fib[i-1] + fib[i-2];
        if(fib[i] >= N) break;
    }
}
int toNum(int *a,int len){
    int res = 0;
    for(int i = 1;i <= len;++i){
        if(a[i]) res += fib[i];
    }
    return res;
}
signed main(void){
    init();
    int a[] = {0,1,0,1};
    cout << toNum(a,3) << endl;
    return 0;
}
