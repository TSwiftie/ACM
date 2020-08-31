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
const int N = 1e5+10;
int n;ll a[N];
signed main(void){
    scanf("%d",&n);for(int i = 1;i <= n;++i) scanf("%lld",a+i);
    printf("1 %d\n",n);for(int i = 1;i <= n;++i) printf("%lld ",-1ll*n*a[i]);
    if(n > 1) {
        printf("\n%d %d\n%lld\n",n,n,1ll*(n-1)*a[n]);
        printf("1 %d\n",n-1);for(int i = 1;i < n;++i) printf("%lld ",1ll*(n-1)*a[i]);
    }else printf("\n1 1\n1\n1 1\n-1\n");
    return 0;
}
