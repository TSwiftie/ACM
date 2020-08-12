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
    int t;for(scanf("%d",&t);t--;){
        ll r, g, b, w;
        scanf("%lld%lld%lld%lld",&r,&g,&b,&w);
        ll minx = min(r,min(g,b)),odd = (r&1) + (g&1) + (b&1);
        if(odd==3||odd==0) printf("Yes\n");
        else if(odd==1 && w%2==0) printf("Yes\n");
        else if(odd==2 && minx >= 1 && w&1) printf("Yes\n");
        else printf("NO\n");
    }
    return 0;
}
