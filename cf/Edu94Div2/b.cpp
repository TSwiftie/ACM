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
int calc(int s,int w,int cs,int cw,int p){
    if(s > w) return calc(w,s,cw,cs,p);
    if(s*cs >= p) return p/s;
    return cs + min((p-s*cs)/w,cw);
}
void solve(){
    int p, f, cs, cw, s, w;
    cin >> p >> f >> cs >> cw >> s >> w;
    int ans = 0;
    for(int i = 0;i <= cs;++i)
        if(s*i <= p){
            int CW = min((p-i*s)/w,cw);
            ans = max(ans,i+CW+calc(s,w,cs-i,cw-CW,f));
        }
    cout << ans << endl;
}
signed main(void){
    IOS;int t;for(cin >> t;t--;) solve();
    return 0;
}
