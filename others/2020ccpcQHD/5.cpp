#include <algorithm>
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
const int N = 2e5+10;
int a[N], b[N], cha[N<<2], n, p, lsh[N<<2];
signed main(void){
    IOS;int t;cin >> t;for(int cas = 1;cas <= t;++cas){
        cin >> n >> p;
        int Max = 0;
        for(int i = 0;i < n;++i){
            cin >> a[i] >> b[i];
            lsh[4*i] = a[i];
            lsh[4*i+1] = b[i];
            lsh[4*i+2] = a[i]*100/p;
            lsh[4*i+3] = b[i]*100/p;
            Max = max(b[i], Max);
        }
        sort(lsh,lsh+4*n);
        for(int i = 0;i < n;++i){
            int al = lower_bound(lsh,lsh+4*n,a[i]) - lsh;
            int ar = lower_bound(lsh,lsh+4*n,a[i]*100/p) - lsh;
            int bl = lower_bound(lsh,lsh+4*n,b[i]) - lsh;
            int br = lower_bound(lsh,lsh+4*n,b[i]*100/p) - lsh;
            ++cha[bl];--cha[ar+1];
            if(br < al) --cha[br+1],++cha[al];
        }
        int s = 0,ans = 0;
        for(int i = 0;i < 4*n+1;++i){
            s += cha[i];
            if(Max <= lsh[i]) ans = max(ans,s);
        }
        cout << "Case #" << cas << ": " << ans << endl;
        for(int i = 0;i < 4*n+1;++i) cha[i] = 0;
    }
    return 0;
}
