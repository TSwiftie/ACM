#include <bits/stdc++.h>
#include <cstdio>
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
const int N = 2e5+10;
struct P{
    int x, y, id;
    bool operator < (const P&t) const{
        return x == t.x ? y < t.y : x < t.x;
    }
}a[N];int ans[N],f[N],s[N],n;
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
int stk[N],t,b[N],d;
signed main(void){
    //freopen("/home/ts/code/in.in", "r", stdin);
    scanf("%d",&n);
    for(int i = 1,x,y;i <= n;++i){
        scanf("%d%d",&x,&y);
        a[i] = (P){x,y,i};
        f[i] = i;s[i] = 1;
    }
    sort(a+1,a+1+n);d = n;
    for(int i = 1;i < n;++i){
        b[a[i].y] = 1;
        while(d&&b[d]) --d;
        if(d > n-i){
            int x = find(i);
            int y = find(i+1);
            if(x!=y){
                f[x] = y;
                s[y] += s[x];
            }
        }
    }
    for(int i = 1;i <= n;++i) ans[a[i].id] = s[find(i)];
    for(int i = 1;i <= n;++i) printf("%d\n",ans[i]);
    return 0;
}
