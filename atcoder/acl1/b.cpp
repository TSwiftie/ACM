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
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b) { d = a;x = 1;y = 0;return; }
    exgcd(b,a%b,d,y,x);
    y -= a/b*x;
}
signed main(void){
    ll n;scanf("%lld",&n);n<<=1;
    ll ans = n%2?n:2*n;
    for(ll i = 1;i*i <= n;++i){
        if(n%i==0 and __gcd(i,n/i)==1){
            ll d,x,y;
            exgcd(i, n/i, d, x, y);
            while(i*x <= 1) { x+=n/i;y-=i; }
            ans = min(ans,i*x-1);
            while(n/i*y <= 1) { x-=n/i;y+=i; }
            ans = min(ans,n/i*y-1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
//a*x + k = 0
//b*y + k = -1
//a*x + b*y + 2*k = -1
//a*x + b*y = -2*k-1
