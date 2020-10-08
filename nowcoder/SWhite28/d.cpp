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
void solve(){
    ll x, y;scanf("%lld%lld",&x,&y);
    if(x < 2*y){ puts("-1");return; }
    ll k = x - 2 * y;
    for(int i = 0;i < 63;++i)
        if(k & (1ll << i) && y & (1ll << i)){ puts("-1");return; }
    printf("%lld\n",k);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
