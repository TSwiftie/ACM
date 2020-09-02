#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int N = 1e5+10;
int a[N],n;
int solve(int l,int r){
    if(l > r) return 0;
    if(l==r) return a[l]!=0;
    int maxn = 1e9+10,mid = l;
    for(int i = l;i <= r;++i) if(a[i] <= maxn){ maxn = a[i]; mid = i; }
    for(int i = l;i <= r;++i) a[i] -= maxn;
    return min(maxn+solve(l,mid-1)+solve(mid+1,r),r-l+1);
}
signed main(void){
    scanf("%lld",&n);for(int i = 1;i <= n;++i) scanf("%lld",a+i);
    printf("%lld\n",solve(1,n));
    return 0;
}
