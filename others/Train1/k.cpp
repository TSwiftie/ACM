#pragma GCC optimize(2)
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
const int N = 1e4+10;
const int K = 5e3+5;
int n, k;
int id[N][5];char s[N][5][5],ans[K];
bool vis[N],ins[N];
vi G[N];
void add_edge(int u,int v){ G[u].push_back(v); }
int dfn[N],low[N],col[N],Stack[N],top,idx,scc;
void tarjan(int u){
    Stack[++top] = u;ins[u] = 1;dfn[u] = low[u] = ++idx;
    for(int v : G[u]){
        if(!dfn[v]){ tarjan(v);low[u] = min(low[u],low[v]); }
        else if(ins[v]) low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u]){
        ++scc;
        do{
            col[Stack[top]] = scc;
            ins[Stack[top]] = 0;
        }while(Stack[top--]!=u);
    }
}
signed main(void){
    scanf("%d%d",&k,&n);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= 3;++j) scanf("%d%s",&id[i][j],s[i][j]);
        for(int j = 1;j <= 3;++j){
            for(int k = 1;k <= 3;++k){
                if(j==k) continue;
                int u = 2*id[i][j]-(s[i][j][0]=='B');
                int v = 2*id[i][k]-(s[i][k][0]=='R');
                add_edge(u, v);
            }
        }
    }
    for(int i = 1;i <= 2*k;++i) if(!dfn[i]) tarjan(i);
    for(int i = 1;i <= 2*k;i+=2) if(col[i]==col[i+1]){ puts("-1");return 0; }
    for(int i = 1;i <= 2*k;i+=2){
        int f1 = col[i],f2 = col[i+1];
        if(vis[f1]){ ans[(i+1)>>1] = 'R';continue; }
        if(vis[f2]){ ans[(i+1)>>1] = 'B';continue; }
        if(f1 < f2){ vis[f1] = 1;ans[(i+1)>>1] = 'R'; }
        else{ vis[f2] = 1;ans[(i+1)>>1] = 'B'; }
    }
    ans[k+1] = 0;
    printf("%s\n",ans+1);
    return 0;
}
