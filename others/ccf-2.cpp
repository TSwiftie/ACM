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
const int N = 1e6+10;
int a[N],b[N],all,n,m;
signed main(void){
    scanf("%lld%lld%lld",&all,&n,&m);
    for(int i = 1,pos,x;i <= n;++i){
        scanf("%lld%lld",&pos,&x);
        a[pos] = x;
    }
    for(int i = 1,pos,x;i <= m;++i){
        scanf("%lld%lld",&pos,&x);
        b[pos] = x;
    }
    int ans = 0;
    for(int i = 1;i <= all;++i)
        ans += a[i] * b[i];
    printf("%lld\n",ans);
    return 0;
}
