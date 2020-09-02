#include <queue>
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
const int N = 1e5+10;
struct Edge{ int v,w,next; }edge[N<<1];
int head[N],tot,n,S,sizf[N],sum;vi tmp;
void add_edge(int u,int v,int w){ edge[++tot].v = v;edge[tot].w = w;edge[tot].next = head[u];head[u] = tot; }
void dfs(int u,int f){
    bool leaf = true;
    for(int i=head[u];i;i=edge[i].next){
        int v = edge[i].v,w = edge[i].w;
        if(v==f) continue;
        leaf = false;
        dfs(v,u);
        sizf[u] += sizf[v];
        sum += sizf[v]*w;
        while(w) tmp.push_back((w-w/2)*sizf[v]),w/=2;
    }
    if(leaf) sizf[u] = 1;
}
void solve(){
    scanf("%lld%lld",&n,&S);
    for(int i=1,u,v,w;i<n;++i){
        scanf("%lld%lld%lld",&u,&v,&w);
        add_edge(u,v,w);add_edge(v,u,w);
    }
    dfs(1,0);
    sort(all(tmp));
    int ans = 0;
    while(sum>S){ ++ans; sum -= tmp.back();tmp.pop_back(); }
    printf("%lld\n",ans);
    memset(sizf,0,sizeof sizf);tmp.clear();
    memset(head,0,sizeof head);tot = 0;sum = 0;
}
signed main(void){
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
