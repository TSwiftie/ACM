/************************************************************
	> File Name: t5.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 01 Jul 2020 08:34:51 PM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int a[1003][1003],idx,n,m;
int vis[1003][1003],block[100004];
bool ischeck[100004];
void dfs(int x,int y){
    ++block[idx];
    vis[x][y] = idx;
    for(int i = 0;i < 4;++i){
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if(dx<0||dx>n||dy<0||dy>m||vis[dx][dy]||!a[dx][dy]) continue;
        dfs(dx,dy);
    }
}
int ans;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            scanf("%d",&a[i][j]);
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j){
            if(!a[i][j]||vis[i][j]) continue;
            ++idx;
            dfs(i,j);
        }
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            a[i][j] = block[vis[i][j]];
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j){
            if(a[i][j]) continue;
            int sum = 0;
            for(int k = 0;k < 4;++k){
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if(dx<0||dx>n||dy<0||dy>m) continue;
                if(ischeck[vis[dx][dy]]) continue;
                ischeck[vis[dx][dy]] = true;
                sum += a[dx][dy];
            }
            for(int k = 0;k < 4;++k){
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if(dx<0||dx>n||dy<0||dy>m) continue;
                ischeck[vis[dx][dy]] = false;
            }
            ans = max(ans,sum+1);
        }
    printf("%d\n",ans);
    return 0;
}
