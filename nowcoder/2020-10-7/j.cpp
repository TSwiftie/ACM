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
const int N = 1e6+10;
int r[N],c[N],R = 0,Rc = 0,C = 0,Cc = 0;
signed main(void){
    int n, q;
    scanf("%lld%lld",&n,&q);
    for(int i = 1;i <= n;++i) r[i] = c[i] = n*(n+1)/2+n*i;
    while(q--){
        char op;int x;
        scanf(" %c%lld",&op,&x);
        if(op=='R'){
            if(r[x]==0) { printf("0\n");continue; }
            printf("%lld\n",r[x]+R-Cc*x);
            r[x] = 0;
            C -= x;++Rc;
        }else{
            if(c[x]==0) { printf("0\n");continue; }
            printf("%lld\n",c[x]+C-Rc*x);
            c[x] = 0;
            R -= x;++Cc;
        }
    }
    return 0;
}
