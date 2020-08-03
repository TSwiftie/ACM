/************************************************************
	> File Name: 4011.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 03 Aug 2020 09:30:08 AM CST
************************************************************/
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
const int N = 13;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int n, m, e[N][N][N][N],cnt[N][N],key[N][N][N];
bool vis[N][N][1<<14];
struct node{
    int x, y, k, d;
    node() { x = y = k = d = 0; }
    node(int _x,int _y,int _k,int _d):x(_x),y(_y),k(_k),d(_d){}
};
int getkey(int x,int y,int ans = 0){ for(int i = 1;i <= cnt[x][y];++i) ans|=(1<<(key[x][y][i]-1)); return ans; }
int bfs(int sx,int sy){
    queue<node>q;
    int sk = getkey(sx,sy);
    q.push(node(sx,sy,sk,0));vis[sx][sy][sk] = true;
    while(q.size()){
        node u = q.front();q.pop();
        if(u.x==n && u.y==m) return u.d;
        for(int i = 0;i < 4;++i){
            int dx = u.x + dir[i][0],dy = u.y + dir[i][1];
            int opt = e[u.x][u.y][dx][dy];
            if(dx<1||dx>n||dy<1||dy>m||opt<0||(opt&&!(u.k&(1<<(opt-1))))) continue;
            int nxt = u.k | getkey(dx,dy);
            if(vis[dx][dy][nxt]) continue;
            q.push(node(dx,dy,nxt,u.d+1));vis[dx][dy][nxt] = true;
        }
    }
    return -1;
}
signed main(void){
    int k, s, p;
    scanf("%d%d%d",&n,&m,&p);
    for(scanf("%d",&k);k--;){
        int x1,y1,x2,y2,g;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
        if(g) e[x1][y1][x2][y2] = e[x2][y2][x1][y1] = g;
        else e[x1][y1][x2][y2] = e[x2][y2][x1][y1] = -1;
    }
    for(scanf("%d",&s);s--;){
        int x, y, q;
        scanf("%d%d%d",&x,&y,&q);
        key[x][y][++cnt[x][y]] = q;
    }
    printf("%d\n",bfs(1,1));
    return 0;
}
