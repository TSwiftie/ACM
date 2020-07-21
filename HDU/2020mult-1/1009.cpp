/************************************************************
	> File Name: 1009.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 02:50:47 PM CST
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
const int N = 5e4+10;
struct node{
    int p,a,id;
}s[N];
bool vis[N];
bool cmp(const node &x,const node &y){
    if(x.p==y.p) return x.a > y.a;
    else x.p > y.p;
}
signed main(void){
    int t, n;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%d%d",&s[i].p,&s[i].a);
            s[i].id = i;
            vis[i] = false;
        }
        sort(s+1,s+1+n,cmp);
        for(int i = 2;i <= n;++i){
            if(s[i].a <= s[1].a || s[i].p == s[1].p) vis[s[i].id] = true;
        }
    }
    return 0;
}
