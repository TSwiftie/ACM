/************************************************************
	> File Name: 5532.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 26 Jun 2020 06:40:52 PM CST
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
const int N = 1e5+10;
int a[N],s[N];
int top,t,n;
bool judge(){
    top = 0;
    for(int i = 0;i < n;++i){
        int pos = upper_bound(s,s+top,a[i])-s;
        s[pos] = a[i];
        top = max(top,pos+1);
    }
    return top >= n-1;
}
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 0;i < n;++i) scanf("%d",a+i);
        bool flag = judge();
        reverse(a,a+n);
        flag |= judge();
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
