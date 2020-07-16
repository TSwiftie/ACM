/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 16时13分37秒
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
//typedef long long ll;
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
typedef __int128 ll;
inline ll read(){
    ll x = 0,f = 1;
    char ch = getchar();
    for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
    return x*f;
}
inline void print(ll x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x/10);
    putchar(x%10+'0');
}
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b){
        d = a;
        x = 1;
        y = 0;
        return ;
    }
    exgcd(b,a%b,d,y,x);
    y -= (a/b)*x;
}
int n;
ll m;
LL a[109],b[109];
ll a1, a2, b1, b2, d, g, x, y;
ll CRT(){
    a1 = a[1];b1 = b[1];
    for(int i = 2;i <= n;++i){
        a2 = a[i];b2 = b[i];
        d = b2 - b1;
        exgcd(a1,a2,g,x,y);
        if(d%g!=0) return -1;
        x = ((x*d/g)%(a2/g)+(a2/g))%(a2/g);
        b1 = x*a1 + b1;
        a1 = a1*a2/g;
    }
    return b1;
}
signed main(void){
    scanf("%d",&n);
    m = read();
    for(int i = 1;i <= n;++i) scanf("%lld%lld",a+i,b+i);
    ll ans = CRT();
    if(ans==-1) printf("he was definitely lying\n");
    else if(ans > m) printf("he was probably lying\n");
    else print(ans);
    return 0;
}
