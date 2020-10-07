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
int n, k, mu[N], pri[N], tot;bool vis[N];
vi fac;
void getMu(){
    mu[1] = 1;
    for(int i = 2;i < N;++i){
        if(!vis[i]) pri[++tot] = i,mu[i] = -1;
        for(int j = 1;j <= tot && i * pri[j] < N;++j){
            vis[i * pri[j]] = true;
            if(i % pri[j]==0){
                mu[i * pri[j]] = 0;
                break;
            }
            mu[i * pri[j]] = -mu[i];
        }
    }
}
void solve(){
    scanf("%lld%lld",&n,&k);
    int x = n;
    while(k){
        if(mu[x]==0) break;
        if(mu[x]==-1 && mu[x-1]==1){ x -= (k&1);break; }
        x += mu[x];
        --k;
    }
    printf("%lld\n",x);
}
signed main(void){
    getMu();
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
