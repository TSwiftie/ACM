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
signed main(void){
    int r1,r2,d1,d2,c1,c2,a,b,c,d;scanf("%d%d%d%d%d%d",&r1,&r2,&d1,&d2,&c1,&c2);
    a = (c1+d1-r2)/2;b = c1-a;c = r1-a;d = r2-b;
    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d&&a&&b&&c&&d&&a<=9&&b<=9&&c<=9&&d<=9){ printf("%d %d\n%d %d\n",a,c,d,b); }
    else printf("-1\n");
    return 0;
}
