#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
const int N = 1e3+10;
char ch[N][N];int n, m, ans, vis[N][N];
queue<pii>q;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) scanf("%s",ch[i]+1);
    for(int i = 1;i <= n;++i){
        if(ch[i][1]=='A') q.push({i,1});
        if(ch[i][m]=='D') q.push({i,m});
        if(i==1 && ch[i][1]=='W') q.push({1,1});
        if(i==1 && ch[i][m]=='W') q.push({1,m});
        if(i==n && ch[i][1]=='S') q.push({n,1});
        if(i==n && ch[i][m]=='S') q.push({n,m});
    }
    for(int i = 2;i < m;++i){
        if(ch[1][i]=='W') q.push({1,i});
        if(ch[n][i]=='S') q.push({n,i});
    }
    while(q.size()){
        pii now = q.front();q.pop();
        int nowx = now.first,nowy = now.second;
        vis[nowx][nowy] = true;++ans;
        if(nowx-1 >= 1 && !vis[nowx-1][nowy] && ch[nowx-1][nowy]=='S') q.push({nowx-1,nowy});
        if(nowy-1 >= 1 && !vis[nowx][nowy-1] && ch[nowx][nowy-1]=='D') q.push({nowx,nowy-1});
        if(nowx+1 <= n && !vis[nowx+1][nowy] && ch[nowx+1][nowy]=='W') q.push({nowx+1,nowy});
        if(nowy+1 <= m && !vis[nowx][nowy+1] && ch[nowx][nowy+1]=='A') q.push({nowx,nowy+1});
    }
    printf("%d\n",ans);
    return 0;
}
