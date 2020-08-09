/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 09 Aug 2020 05:20:30 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int p = 1e9+7;
const int N = 1e5+10;
char ch[N];int T;
int ksm(int a,int b,int res = 1){ for(;b;a = a * a % p,b >>= 1) if(b&1) res = res * a % p; return res; }
signed main(void){
    for(scanf("%lld",&T);T--;){
        int ans = 0;
        scanf("%s",ch+1);int n = strlen(ch+1);
        int one = 0,zero = 0;
        for(int i = n;i >= 1;--i){
            if(ch[i]=='1')
                ans = (ans + ksm(3,one)*ksm(2,zero)%p)%p;
            if(ch[i]=='1') ++one;
            else ++zero;
        }
        printf("%lld\n",(ans+1)%p);
    }
    return 0;
}
