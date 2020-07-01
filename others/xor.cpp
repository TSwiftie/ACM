/************************************************************
	> File Name: xor.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 01 Jul 2020 10:32:53 AM CST
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
const int N = 1e6+10,M = (1<<21);
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x*f;
}
int n, q, a[N];
bool vis[M];
signed main(void){
    n = read();q = read();
    for(int i = 1;i <= n;++i){
        a[i] = read();
        vis[a[i]] = true;
    }
    while(q--){
        int k = read(),x = read(),y = read();
        if((a[x]^a[y])==k) puts("1");
        else if(a[x]!=a[y]) puts("-1");
        else if(vis[k^a[x]]) puts("2");
        else puts("-1");
    }
    return 0;
}
