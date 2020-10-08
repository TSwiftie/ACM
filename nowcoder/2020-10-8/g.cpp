#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <iomanip>
//#include <unordered_map>
#define lowbit(x) (x & -x)
#define lc o << 1
#define rc o << 1 | 1
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
const int MAXM = 2e5 + 5;
const int MOD = 1e9 + 7;
const int dir[4][2] = { 1, 0, -1, 0, 0, 1, 0, -1 };
const double PI = acos(-1.0);
const double EXP = 1e-8;
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
    while (isdigit(c)) { x = x * 10 + c - '0';c = getchar(); }
    return f * x;
}
int n, rt, m;
int sz[MAXN], rev[MAXN], ch[MAXN][2], id[MAXN], fa[MAXN], val[MAXN];
inline bool chk(int o) { return ch[fa[o]][1] == o; }
inline void Rev(int o) { swap(ch[o][0], ch[o][1]);rev[o] ^= 1; }
inline void pushup(int o) { sz[o] = sz[ch[o][0]] + sz[ch[o][1]] + 1; }
inline void pushdown(int o) {
    if (rev[o]) {
        if (ch[o][0]) Rev(ch[o][0]);
        if (ch[o][1]) Rev(ch[o][1]);
        rev[o] = 0;
    }
}
inline void rotate(int o) {
    int op = fa[o], opp = fa[op], k = chk(o), v = ch[o][k ^ 1];
    ch[o][k ^ 1] = op, ch[op][k] = v, ch[opp][chk(op)] = o;
    fa[o] = opp, fa[op] = o, fa[v] = op;
    pushup(op);
    pushup(o);
}
inline void splay(int o, int goal = 0) {
    while (fa[o] != goal) {
        int op = fa[o], opp = fa[op];
        if (opp != goal) chk(o) == chk(op) ? rotate(op) : rotate(o);
        rotate(o);
    }
    if (!goal) rt = o;
}
inline int kth(int k) {
    int cur = rt;
    while (true) {
        pushdown(cur);
        if (sz[ch[cur][0]] >= k) cur = ch[cur][0];
        else if (sz[ch[cur][0]] + 1 == k) return cur;
        else k -= sz[ch[cur][0]] + 1, cur = ch[cur][1];
    }
}
void build(int l, int r, int pa) {
    int mid = (l + r) >> 1;
    if (l == r) {
        ch[id[pa]][pa < mid] = id[mid], val[id[mid]] = mid;
        fa[id[mid]] = id[pa];
        sz[id[mid]] = 1;
        return;
    } else {
        if (l < mid) build(l, mid - 1, mid);
        if (mid < r) build(mid + 1, r, mid);
    }
    ch[id[pa]][pa < mid] = id[mid];
    fa[id[mid]] = id[pa];
    val[id[mid]] = mid;
    sz[id[mid]] = 1;
    pushup(id[mid]);
}
void dfs(int o) {
    if (!o) return;
    pushdown(o);
    dfs(ch[o][0]);
    if (val[o] != 0 && val[o] != n + 1) cout << val[o] << " ";
    dfs(ch[o][1]);
}
void Reverse(int l,int r){
    int ll = kth(l), rr = kth(r + 2);
    splay(ll);
    splay(rr, ll);
    Rev(ch[rr][0]);
}
int main(void) {
    IOS;cin >> n >> m;
    for (int i = 0; i <= n + 1; i++) id[i] = i + 1;
    build(0, n + 1, n + 4);
    rt = (3 + n) >> 1;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        r = l+r-1;
        Reverse(1, l-1);
        Reverse(l, r);
        Reverse(1, r);
    }
    dfs(rt);
    cout << endl;
    return 0;
}
