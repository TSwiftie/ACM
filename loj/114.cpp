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
ll bit[64],a[64],x,k;
signed main(void){
    int n, m, cnt = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;++i){
        scanf("%lld",&x);
        for(int j = 50;~j;--j){
            if(x&(1ll<<j)){
                if(!bit[j]) { bit[j] = x;break; }
                x^=bit[j];
            }
        }
    }
    for(int i = 50;~i;--i)
        for(int j = i-1;~j;--j)
            if(bit[i]&(1ll<<j)) bit[i]^=bit[j];
    for(int i = 0;i <= 50;++i)
        if(bit[i]) a[cnt++] = bit[i];
    for(scanf("%d",&m);m--;){
        scanf("%lld",&k);
        if(cnt!=n) --k;
        if(k >= (1ll << cnt)) puts("-1");
        else{
            ll ans = 0;
            for(int i = 0;i < cnt;++i) if(k&(1LL<<i)) ans^=a[i];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
