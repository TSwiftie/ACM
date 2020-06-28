/************************************************************
	> File Name: hosrspool.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 28 Jun 2020 11:01:11 AM CST
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
const int N = 7e5+10;
int tab[300];
char str[N],text[N];
int bFind(){
    int n = strlen(str),m = strlen(text);
    for(int i = 0;i < 255;++i) tab[i] = n;
    for(int i = 0;i < n-1;++i) tab[str[i]] = n-i-1;
    int i = n-1;
    while(i <= m-1){
        int k = 0;
        while(str[n-k-1]==text[i-k] && k < n) ++k;
        if(k==n) return i-n+1;
        else i += tab[text[i]];
    }
    return -1;
}
signed main(void){
    scanf("%s%s",str,text);
    printf("%d\n",bFind());
    return 0;
}
