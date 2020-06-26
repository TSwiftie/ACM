/************************************************************
	> File Name: 2280.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 26 Jun 2020 10:40:21 AM CST
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
int n,r,s[5010][5010];
inline int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x*f;
}
int ans;
signed main(void){
    n = read();r = read();
    for(int i = 1,x,y,z;i <= n;++i){
        x = read();y = read();z = read();
        s[x+1][y+1] = z;
    }
    for(int i = 1;i <= 5001;++i)
        for(int j = 1;j <= 5001;++j)
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
    for(int i = 0;i <= 5001-r;++i)
        for(int j = 0;j <= 5001-r;++j)
            ans = max(ans,s[i+r][j+r]-s[i+r][j]-s[i][j+r]+s[i][j]);
    printf("%d\n",ans);
    return 0;
}
