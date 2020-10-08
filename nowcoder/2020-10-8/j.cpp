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
bool vis[N];int pri[N],tot,pre[N],n;
void init(){
    vis[1] = true;
    for(int i = 2;i < N;++i){
        if(!vis[i]) pri[++tot] = i;
        for(int j = 1;j <= tot && i*pri[j] < N;++j){
            vis[i*pri[j]] = true;
            if(i%pri[j]==0) break;
        }
    }
    pre[1] = 0;
    for(int i = 2;i < N;++i) pre[i] = pre[i-1] + (vis[i]==false);
}
signed main(void){
    init();
    scanf("%lld",&n);
    int ans = 0;
    for(int i = 1;i <= n;++i){
        int tmp = pre[n/i];
        if(tmp <= 1) break;
        ans += tmp*(tmp-1)/2;
    }
    printf("%lld\n",ans<<1);
    return 0;
}
