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
const int N = 25;
int ma[N][N],mb[N][N],mc[N][N];
signed main(void){
    int m, n, p, q, cas = 0;while(~scanf("%d%d%d%d",&m,&n,&p,&q)){
        if(!m && !n && !p && !q) return 0;
        for(int i = 1;i <= m;++i)
            for(int j = 1;j <= n;++j) scanf("%d",&ma[i][j]);
        for(int i = 1;i <= p;++i)
            for(int j = 1;j <= q;++j) scanf("%d",&mb[i][j]);
        printf("Case #%d:\n",++cas);
        if(n!=p) { printf("undefined\n");continue; }
        memset(mc,0,sizeof mc);
        for(int i = 1;i <= m;++i)
            for(int j = 1;j <= q;++j)
                for(int k = 1;k <= n;++k)
                    mc[i][j] += ma[i][k] * mb[k][j];
        for(int i = 1;i <= m;++i){
            printf("| ");
            for(int j = 1;j <= q;++j)
                printf("%d ",mc[i][j]);
            printf("|\n");
        }
    }
    return 0;
}
