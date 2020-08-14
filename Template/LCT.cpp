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
const int N = 2e5+10;
struct LCT{
    int ch[N][2],fa[N],tag[N];
    void init(){ memset(ch,0,sizeof ch);memset(fa,0,sizeof fa);memset(tag,0,sizeof tag); }
    void clear(int x){ ch[x][0] = ch[x][1] = fa[x] = tag[x] = 0; }
    int getch(int x){ return ch[fa[x]][1]==x; }
    int isroot(int x){ return ch[fa[x]][0]!=x && ch[fa[x]][1]!=x; }
    void pushdown(int x){
        if(tag[x]){
            if(ch[x][0]) swap(ch[ch[x][0]][0],ch[ch[x][0]][1]),tag[ch[x][0]] ^= 1;
            if(ch[x][1]) swap(ch[ch[x][1]][0],ch[ch[x][1]][1]),tag[ch[x][1]] ^= 1;
            tag[x] = 0;
        }
    }
    void update(int x){ if(!isroot(x)) update(fa[x]);pushdown(x); }
    void rotate(int x){
        int y = fa[x],z = fa[y],chx = getch(x),chy = getch(y);
        fa[x] = z;
        if(!isroot(y)) ch[z][chy] = x;
        ch[y][chx] = ch[x][chx^1];
        fa[ch[x][chx^1]] = y;
        ch[x][chx^1] = y;
        fa[y] = x;
    }
    void splay(int x){
        update(x);
        for(int f = fa[x];f = fa[x],!isroot(x);rotate(x))
    }
};
