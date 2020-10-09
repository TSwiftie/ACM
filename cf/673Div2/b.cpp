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
const char *INPUT = "/home/ts/code/in.in";
void solve(){
    int n;ll T;scanf("%d%lld",&n,&T);
    int cur = 0;
    for(int i = 1,x,r;i <= n;++i){
        scanf("%d",&x);
        if(T%2==0 && x == T/2) r = (cur++)%2;
        else if(2*x < T) r = 0;
        else r = 1;
        printf("%d%c",r," \n"[i==n]);
    }
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
