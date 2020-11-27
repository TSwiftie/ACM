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
const int N = 35;
int suf[N],mid[N],ls[N],rs[N];
int dfs(int sl,int sr,int ml,int mr){
    if(sl>sr) return -1;
    if(ml>mr) return -1;
    if(sl==sr) return suf[sl];
    if(ml==mr) return mid[ml];
    int rt = suf[sr],pos;
    for(pos = ml;pos <= mr;++pos)
        if(rt==mid[pos]) break;
    int lcnt = pos-ml;
    ls[rt] = dfs(sl,sl+lcnt-1,ml,pos-1);
    rs[rt] = dfs(sl+lcnt,sr-1,pos+1,mr);
    return rt;
}
signed main(void){
    int n;scanf("%d",&n);
    memset(ls,-1,sizeof ls);
    memset(rs,-1,sizeof rs);
    for(int i = 1;i <= n;++i) scanf("%d",suf+i);
    for(int i = 1;i <= n;++i) scanf("%d",mid+i);
    int root = dfs(1,n,1,n);
    queue<int>q;q.push(root);
    vi ans;int cnt = 0;
    while(q.size()){
        int u = q.front();q.pop();
        ans.push_back(u);
        if(ls[u]!=-1) q.push(ls[u]);
        if(rs[u]!=-1) q.push(rs[u]);
    }
    printf("%d",ans[0]);
    for(int i = 1;i < SZ(ans);++i) printf(" %d",ans[i]);
    puts("");
    return 0;
}
