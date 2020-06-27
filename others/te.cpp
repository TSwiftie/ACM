/************************************************************
	> File Name: hosrspool.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 27 Jun 2020 09:06:05 AM CST
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
int tab[355];
char ch[N],sh[N];
int Find(char *s,char *t,int n,int m){
    for(int i = 0;i < 255;++i) tab[i] = m;
    for(int i = 0;i < m-1;++i) tab[t[i]] = m-1-i;
    int i = m-1;
    while(i <= n-1){
        int k = 0;
        while(k <= m-1 && t[m-1-k]==s[i-k]) ++k;
        if(k==m) return i-m+1;
        else i += tab[s[i]];
    }
    return -1;
}
signed main(void){
    scanf("%s%s",sh,ch);
    int n = strlen(ch);
    int m = strlen(sh);
    printf("%d\n",Find(ch,sh,n,m));
    return 0;
}
