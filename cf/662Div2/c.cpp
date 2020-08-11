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
int n, a[N], last, buc[N];
bool check(int x){
    int Max = 0;
    for(int i = 1;i <= n;++i){
    }
}
void solve(){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d",a+i);
        ++buc[a[i]];
    }
    for(int i = 1;i <= n;++i)
        if(buc[i]==1) ++last,buc[i];
    int l = 0,r = n,ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)){ ans = mid;l = mid+1; }
        else r = mid-1;
    }
    printf("%d\n",ans);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
