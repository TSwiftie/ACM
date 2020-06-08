/************************************************************
	> File Name: 517.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 08 Jun 2020 07:04:34 PM CST
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
const int MAXN = 20 + 5;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x*f;
}
int N, M;
int a[MAXN * MAXN];
int idx[MAXN][MAXN], val[MAXN][MAXN];
int p[MAXN], ti[MAXN];
bool vis[MAXN][MAXN * MAXN];
inline bool ok(int &st, int &len, int &mac) {
    for(int i = st; i <= st + len - 1; i++) 
        if(vis[mac][i]) return false;
    for(int i = st; i <= st + len - 1; i++) vis[mac][i] = true;
    return true;
}
signed main(void){
    cin>>M>>N;
    for(int i = 1; i <= N * M; i++) a[i] = read();
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) idx[i][j] = read();
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++) val[i][j] = read();
    for(int i = 1; i <= N * M; i++) {
        ++p[a[i]]; int &t = ti[a[i]];
        while(!ok(t, val[ a[i] ][ p[a[i]] ], idx[ a[i] ][ p[a[i]] ])) ++t;
        t += val[ a[i] ][ p[a[i]] ];
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) ans = max(ans, ti[i]); 
    printf("%d\n", ans);
    return 0;
}

