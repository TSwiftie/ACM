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
const int N = 2e6+10;
int n, q, k;int a[N],sum[N];
signed main(void){
    scanf("%d%d%d",&n,&k,&q);
    for(int i = 1;i <= n;++i){
        scanf("%d",a+i);
        sum[i] = sum[i-1];
        if(a[i-1]!=a[i]) ++sum[i];
    }
    for(int i = 1;i <= n;++i) printf("%d ",sum[i]);
    puts("");
    while(q--){
        int x, y;scanf("%d%d",&x,&y);
        if(sum[y]-sum[x]>=k) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
