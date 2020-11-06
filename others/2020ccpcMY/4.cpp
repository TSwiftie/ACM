#include <algorithm>
#include <bits/stdc++.h>
#include <ext/rope>
#include <sched.h>
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
const int N = 1e5+10;
ll a[N];int n;
bool check(ll x){
    ll sum = 0;
    for(int i = 1;i <= n;++i){
        if(a[i] < x-1) sum += 0-(a[i]-x+1);
        if(sum > x-1) return false;
    }
    return true;
}
signed main(void){
    int t;scanf("%d",&t);for(int cas = 1;cas <= t;++cas){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i) scanf("%lld",a+i);
        ll l = 0,r = 1e18,ans = 1;
        while(l <= r){
            ll mid = (l+r)>>1;
            if(check(mid)) ans = mid,l = mid+1;
            else r = mid-1;
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
