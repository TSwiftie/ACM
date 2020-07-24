/************************************************************
	> File Name: 1010.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 24 Jul 2020 06:23:52 PM CST
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
const int N = 55;
int T, n, m, x, cnt[N], nxt[N], e[N][N][4];
ll ans;
void dfs(int x,int a,int b,int c,int d){
    if(x > m){
        ll tmp = 1LL * a * b * c * d;
        if(tmp > ans) ans = tmp;
        return ;
    }
    int num = cnt[x];
    if(!num){
        dfs(nxt[x],a,b,c,d);
        return ;
    }
    for(int i = 1;i <= num;++i) dfs(x+1,a+e[x][i][0],b+e[x][i][1],c+e[x][i][2],d+e[x][i][3]);
}
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;++i) cnt[i] = 0;
        while(n--){
            scanf("%d",&x);
            ++cnt[x];
            for(int j = 0;j < 4;++j) scanf("%d",&e[x][cnt[x]][j]);
        }
        x = m + 1;
        for(int i = m;i;--i){
            nxt[i] = x;
            if(cnt[i]) x = i;
        }
        ans = 0;
        dfs(1,100,100,100,100);
        printf("%lld\n",ans);
    }
    return 0;
}
