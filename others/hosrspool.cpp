/************************************************************
	> File Name: hosrspool.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 27 Jun 2020 09:35:32 AM CST
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
mt19937 rnd(time(0));
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
const int N = 7e5+10;
int tab[300];
char s[N],t[N];
int bFind(){
    int ls = strlen(s),lt = strlen(t);
    for(int i = 0;i < ls-1;++i) tab[s[i]-'A'] = ls-i-1;
    int p = ls - 1;
    while(p < lt){
        int k = 0;
        while(s[ls-k-1]==t[p-k]&&k <= ls) ++k;
        if(k==ls) return p-ls+1;
        else p += tab[t[p]-'A'];
    }
    return -1;
}
signed main(void){
    scanf("%s%s",s,t);
    printf("%d\n",bFind());
    return 0;
}
