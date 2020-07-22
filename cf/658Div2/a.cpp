/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 22 Jul 2020 10:33:29 AM CST
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
const int N = 1e3+10;
int n, m;
bool vis[N];
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d%d",&n,&m);
        int ans = -1;
        for(int i = 1,x;i <= n;++i){
            scanf("%d",&x);
            vis[x] = true;
        }
        for(int i = 1,x;i <= m;++i){
            scanf("%d",&x);
            if(vis[x]) ans = x;
        }
        if(ans==-1) printf("NO\n");
        else{
            printf("YES\n");
            printf("1 %d\n",ans);
        }
        memset(vis,false,sizeof vis);
    }
    return 0;
}
