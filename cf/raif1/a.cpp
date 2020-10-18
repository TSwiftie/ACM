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
const char *INPUT = "/home/ts/code/in.in";
signed main(void){
    int t;for(scanf("%d",&t);t--;){
        ll x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        if(abs(x1-x2)==0 || abs(y1-y2)==0) printf("%lld\n",abs(x1-x2)+abs(y1-y2));
        else printf("%lld\n",abs(x1-x2)+abs(y1-y2)+2);
    }
    return 0;
}
