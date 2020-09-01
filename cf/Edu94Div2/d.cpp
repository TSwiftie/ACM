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
const int N = 3e3+10;
int a[N],n,t,buc[N*N];
void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){ scanf("%d",a+i);--a[i]; }
    int ans = 0;
    for(int j = n;j >= 1;--j){
        int k = j+1;
        for(int l = k+1;l <= n;++l) ++buc[a[k]*n+a[l]];
        for(int i = 1;i < j;++i) ans += buc[a[i]*n+a[j]];
    }
    printf("%d\n",ans);
    memset(buc,0,sizeof buc);
}
signed main(void){
    for(scanf("%d",&t);t--;) solve();
    return 0;
}
