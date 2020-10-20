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
const char *INPUT = "/home/ts/code/in.in";
signed main(void){
    IOS;int t;cin >> t;for(int cas = 1;cas <= t;++cas){
        int n, k;cin >> n >> k;int ans = 0;
        for(int i = 1;i <= n;++i){
            cout << i << " : " << floor(pow(i,1.0/k)) << endl;
        }
        /*
         * if(k==1) cout << "Case #" << cas << ": " << n << endl;
         * else{
         *     for(int i = 1;i <= n;++i){
         *         int l = pow(i,k),r = pow(i+1,k)-1;
         *         if(l > n) break;r = min(r,n);
         *         ans += (r/i) - ((l-1)/i);
         *     }
         *     cout << "Case #" << cas << ": " << ans << endl;
         * }
         */
    }
    return 0;
}
