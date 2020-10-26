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
const int N = 1e7+10;
int mu[N],p[N],tot,vis[N];
int sn[N],sm[N];
int n, m, k, t;
void init(){
    mu[1] = 1;
    for(int i = 2;i < N;++i){
        if(!vis[i]) p[++tot] = i,mu[i] = -1;
        for(int j = 1;j <= tot and i*p[j] < N;++j){
            vis[i * p[j]] = 1;
            if(i % p[j] == 0){
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
    for(int i = 1;i < N;++i) mu[i] += mu[i-1];
}
int Sum1(int x,int flg,int ans = 0){
    for(int l = 1,r;l <= x;l = r+1){
        r = x/(x/l);
        if(flg) ans += (x/l)*(x/l)*(sn[r]-sn[l-1]);
        else ans += (x/l)*(x/l)*(sm[r]-sm[l-1]);
    }
    return ans;
}
int Sum2(int x,int flg,int ans = 0){
    for(int l = 1,r;l <= x;l = r+1){
        r = x/(x/l);
        ans += (mu[r]-mu[l-1])*Sum1(x/l,flg);
    }
    return ans;
}
signed main(void){
    init();
    IOS;for(cin >> t;t--;){
        cin >> n >> m;
        for(int i = 1;i <= n;++i) sn[i] = sn[i-1] + m*i/n;
        for(int i = 1;i <= m;++i) sm[i] = sm[i-1] + n*i/m;
        int d = __gcd(n,m);
        cout << Sum2(n,1) + Sum2(m,0) - d*d << endl;
    }
    return 0;
}
