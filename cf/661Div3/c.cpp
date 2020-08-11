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
const int N = 101;
int d[N],n,x,t,ans;
void solve(){
    scanf("%d",&n);ans = 0;
    for(int i = 1;i <= n;++i) scanf("%d",&x),d[x]++;
    for(int i = 1;i <= 100;++i){
        int c = 0;
        for(int j = 0;j <= i;++j) c += min(d[j],d[i-j]);
        ans = max(ans,c/2);
    }
    printf("%d\n",ans);
    memset(d,0,sizeof d);
}
signed main(void){
    for(scanf("%d",&t);t--;) solve();
    return 0;
}
