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
const int N = 55;
int a[N],b[N];
signed main(void){
    int t,n;for(scanf("%lld",&t);t--;){
        int mina = INF,minb = INF,ans = 0;
        scanf("%lld",&n);
        for(int i = 1;i <= n;++i) scanf("%lld",a+i),mina = min(a[i],mina);
        for(int i = 1;i <= n;++i) scanf("%lld",b+i),minb = min(b[i],minb);
        for(int i = 1;i <= n;++i){
            ans += max(a[i]-mina,b[i]-minb);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
