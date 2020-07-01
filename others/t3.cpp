/************************************************************
	> File Name: t3.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 01 Jul 2020 06:23:18 PM CST
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
const int N = 1e5+10;
struct node{
    int l,r;
}s[N];
int n;
bool mark;
signed main(void){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d%d",&s[i].l,&s[i].r);
        if(i>1){
            if(s[i].l==s[i-1].r||s[i].l==s[i-1].l||s[i].r==s[i-1].l||s[i].r==s[i-1].r){
            }else{
                mark = true;
            }
        }
    }
    if(mark) printf("-1\n");
    return 0;
}
