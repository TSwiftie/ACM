/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 09 Aug 2020 11:21:30 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
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
const int N = 1e2+10;
struct node{ int x,y; };
char ch[N][N];int n,m,_;
signed main(void){
    for(scanf("%d",&_);_--;){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i)
            scanf("%s",ch[i]+1);
        int ans = 0;
        for(int i = 1;i <= n;++i)
            if(ch[i][m]=='R') ++ans;
        for(int i = 1;i <= m;++i)
            if(ch[n][i]=='D') ++ans;
        printf("%d\n",ans);
    }
    return 0;
}
