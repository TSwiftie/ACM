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
const int N = 2e5+10;
int n, m, d, cnt, a[N], sum[N];
void solve(void){
    cin >> n >> d >> m;int ans = 0;
    for(int i = 1;i <= n;++i) cin >> a[i],cnt += (a[i] <= m);
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;++i) sum[i] = sum[i-1] + a[i];
    for(int i = 0;i <= n-cnt;++i){
        if((i-1)*(d+1)<n){
            int x = min(cnt,n-(i-1)*(d+1)-1);
            ans = max(ans,sum[n]-sum[n-i]+sum[cnt]-sum[cnt-x]);
        }
    }
    cout << ans << endl;
}
signed main(void){
    IOS;solve();
    return 0;
}
