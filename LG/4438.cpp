/************************************************************
	> File Name: 4438.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月17日 星期五 13时00分52秒
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
const int N = 4e4+1;
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1) + (x<<3) + (ch^48);
    return x * f;
}
int n, m, Top,tot;
int a[N],b[N],c[N],s[N],t[N],Num[N],S[N];
ll f[82][41][41];
void dfs(int u,int x,int y){
    int p = Num[u] = Top?S[Top--]:++tot;
    if(!s[u]){
        for(int i = 0;i <= x;++i)
            for(int j = 0;j <= y;++j)
                f[p][i][j] = (ll)c[u]*(a[u]+i)*(b[u]+j);
        return ;
    }
    dfs(s[u],x+1,y);dfs(t[u],x,y+1);
    int ls = Num[s[u]],rs = Num[t[u]];
    for(int i = 0;i <= x;++i)
        for(int j = 0;j <= y;++j)
            f[p][i][j] = min(f[ls][i+1][j]+f[rs][i][j],f[ls][i][j]+f[rs][i][j+1]);
    S[++Top] = ls,S[++Top] = rs;
}
signed main(void){
    n = read();
    m = 2*n-1;
    int u, v;
    for(int i = 1;i < n;++i){
        u = read();
        v = read();
        s[i] = u<0?n-1-u:u;
        t[i] = v<0?n-1-v:v;
    }
    for(int i = n;i <= m;++i){
        a[i] = read();
        b[i] = read();
        c[i] = read();
    }
    dfs(1,0,0);
    printf("%lld\n",f[Num[1]][0][0]);
    return 0;
}
