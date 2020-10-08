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
const int N = 1e2+10;
int n, m;ll a[N][N],ans;
void solve(){
    scanf("%d%d",&n,&m);ans = 0;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            scanf("%lld",&a[i][j]);
    for(int i = 1;i <= ceil(1.0*n/2);++i){
        for(int j = 1;j <= ceil(1.0*m/2);++j){
            vll tmp;
            tmp.push_back(a[i][j]);
            if(i!=n-i+1 && j==m-j+1) tmp.push_back(a[n-i+1][j]);
            else if(i==n-i+1 && j!=m-j+1) tmp.push_back(a[i][m-j+1]);
            else if(i!=n-i+1 && j!=m-j+1) {
                tmp.push_back(a[i][m-j+1]);
                tmp.push_back(a[n-i+1][j]);
                tmp.push_back(a[n-i+1][m-j+1]);
            }
            sort(all(tmp));
            if(SZ(tmp)==2) ans += (tmp[1]-tmp[0]);
            else if(SZ(tmp)==4) ans += (tmp[3]-tmp[0]+tmp[2]-tmp[1]);
        }
    }
    printf("%lld\n",ans);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
