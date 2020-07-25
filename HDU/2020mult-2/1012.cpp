/************************************************************
	> File Name: 1012.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 25 Jul 2020 09:31:29 AM CST
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
const int N = 1e5+10;
int T, Q, g[N][30], n, m, f[30][30];char A[N], B[30];
inline void up(int &a,int b){ a > b ? (a=b) : 0; }
inline int calc(int l,int r){
    for(int i = 0;i <= m;++i)
        for(int j = 0;j <= i;++j) f[i][j] = N;
    f[0][0] = l-1;
    for(int i = 0;i < m;++i)
        for(int j = 0;j <= i;++j){
            up(f[i+1][j],f[i][j]);
            if(f[i][j] < r) up(f[i+1][j+1],g[f[i][j]+1][B[i+1]]);
        }
    for(int i = m;i;--i)
        for(int j = i;j <= m;++j)
            if(f[j][i] <= r) return i;
    return 0;
}
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%s%s",A+1,B+1);
        n = strlen(A+1),m = strlen(B+1);
        for(int i = 1;i <= n;++i) A[i] -= 'a';
        for(int i = 1;i <= m;++i) B[i] -= 'a';
        for(int i = 0;i < 26;++i) g[n+1][i] = n+1;
        for(int i = n;i;--i){
            for(int j = 0;j < 26;++j) g[i][j] = g[i+1][j];
            g[i][A[i]] = i;
        }
        for(scanf("%d",&Q);Q--;){
            int l, r;
            scanf("%d%d",&l,&r);
            printf("%d\n",r-l+1+m-2*calc(l,r));
        }
    }
    return 0;
}
