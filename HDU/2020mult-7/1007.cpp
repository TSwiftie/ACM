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
const int N = 2e3+10;
int _,n,res;bool vis[N];
struct node{ int x,y; }t[N];
inline int dis(node a,node b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
void calc(){
    int res = 0;
    for(int i=1;i<=n;++i){
        vis[i]=false;
        for(int j=i+1;j<=n;++j) res=max(res,dis(t[i],t[j]));
    }
    for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j)
        if(dis(t[i],t[j])==res) vis[i]=true,vis[j]=true;
    vector<node>v;
    for(int i=1;i<=n;++i) if(!vis[i]) v.push_back(t[i]);
    n = v.size();
    for(int i=1;i<=n;++i) t[i]=v[i-1];
}
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;++i) scanf("%lld%lld",&t[i].x,&t[i].y);
    int xx=t[1].x,yy=t[1].y;
    while(n>2) calc();
    if(n!=1) { printf("YES\n");return; }
    if(t[1].x==xx&&t[1].y==yy) printf("NO\n");
    else printf("YES\n");
}
signed main(void){
    for(scanf("%lld",&_);_--;) solve();
    return 0;
}
