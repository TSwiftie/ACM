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
const int N = 1e3+10;
int n, m, a[N], b[N];
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) scanf("%d%d",a+i,b+i);
    while(m--){
        int x,y,t,cnt = 0;scanf("%d%d%d",&x,&y,&t);
        for(int i = 1;i <= n;++i){
            int len = 2*(b[i]-a[i]),pos;
            int tt = t%len;
            if(tt < len/2) pos = a[i] + tt;
            else pos = a[i] + len - tt;
            if(pos >= x && pos <= y) ++cnt;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
