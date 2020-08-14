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
const int maxn = 3e5+10;
struct LCT {
    int ch[maxn][2], fa[maxn], tag[maxn];
    void init(){ memset(ch,0,sizeof ch);memset(fa,0,sizeof fa);memset(tag,0,sizeof tag); }
    void clear(int x) { ch[x][0] = ch[x][1] = fa[x] = tag[x] = 0; }
    int getch(int x) { return ch[fa[x]][1] == x; }
    int isroot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
    void pushdown(int x) {
        if (tag[x]) {
            if (ch[x][0]) swap(ch[ch[x][0]][0], ch[ch[x][0]][1]), tag[ch[x][0]] ^= 1;
            if (ch[x][1]) swap(ch[ch[x][1]][0], ch[ch[x][1]][1]), tag[ch[x][1]] ^= 1;
            tag[x] = 0;
        }
    }
    void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
    }
    void rotate(int x) {
        int y = fa[x], z = fa[y], chx = getch(x), chy = getch(y);
        fa[x] = z;
        if (!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx ^ 1];
        fa[ch[x][chx ^ 1]] = y;
        ch[x][chx ^ 1] = y;
        fa[y] = x;
    }
    void splay(int x) {
        update(x);
        for (int f = fa[x]; f = fa[x], !isroot(x); rotate(x))
            if (!isroot(f)) rotate(getch(x) == getch(f) ? f : x);
    }
    void access(int x) {
        for (int f = 0; x; f = x, x = fa[x]) splay(x), ch[x][1] = f;
    }
    void makeroot(int x) {
        access(x);
        splay(x);
        swap(ch[x][0], ch[x][1]);
        tag[x] ^= 1;
    }
    int find(int x) {
        access(x);
        splay(x);
        while (ch[x][0]) x = ch[x][0];
        splay(x);
        return x;
    }
    bool IsConnect(int u,int v){ return find(u)==find(v); }
    void Cut(int u,int v){ makeroot(u),access(v),splay(v),ch[v][0] = fa[u] = 0; }
    void link(int u,int v){ makeroot(u);splay(u);fa[u] = v; }
} st;
int n, m, q, l[maxn],r[maxn], Max[maxn];
void solve(){
    st.init();
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i <= m;++i){
        scanf("%d%d",l+i,r+i);
    }
    int L = 1,R = 1;
    while(L <= m){
        if(R <= m && !st.IsConnect(l[R], r[R])){ st.link(l[R],r[R]);++R; }
        else { Max[L] = R;st.Cut(l[L], r[L]);++L; }
    }
    int last = 0;
    while(q--){
        int u, v;
        scanf("%d%d",&u,&v);
        u = (u^last)%m+1;v = (v^last)%m+1;
        if(u > v) swap(u,v);
        if(v >= Max[u]) last = 1,puts("Yes");
        else last = 0,puts("No");
    }
}
signed main(void){
    int T;for(scanf("%d",&T);T--;) solve();
    return 0;
}
