/************************************************************
	> File Name: 95.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 02 Apr 2020 08:32:40 PM CST
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
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int INF = 0x3f3f3f3f;
const ll INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 105;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
bool vis[N][N][17],mark;
char ch[N][N];
struct node{
	int x,y;
	int step,key;
};
int judgeDoor(char c){
	if(c=='B') return 1;
	else if(c=='Y') return 1<<1;
	else if(c=='R') return 1<<2;
	else if(c=='G') return 1<<3;
	return 0;
}
int judgeKey(char c){
	if(c=='b') return 1;
	else if(c=='y') return 1<<1;
	else if(c=='r') return 1<<2;
	else if(c=='g') return 1<<3;
	return 0;
}
int n, m;
void bfs(int sx,int sy){
	node s;
	s.x = sx;s.y = sy;
	s.step = s.key = 0;
	queue<node>q;
	vis[sx][sy][0] = true;
	q.push(s);
	while(q.size()){
		node t = q.front();
		q.pop();
		if(ch[t.x][t.y]=='X'){
			printf("Escape possible in %d steps.\n",t.step);
			return ;
		}
		for(int i = 0;i < 4;i++){
			node cur = t;
			cur.x += dir[i][0];
			cur.y += dir[i][1];
			cur.step++;
			cur.key |= judgeKey(ch[cur.x][cur.y]);
			if(cur.x<0||cur.x>=n||cur.y<0||cur.y>=m||ch[cur.x][cur.y]=='#') continue;
			if(vis[cur.x][cur.y][cur.key]) continue;
			if(judgeDoor(ch[cur.x][cur.y])&&!(cur.key&judgeDoor(ch[cur.x][cur.y]))) continue;
			vis[cur.x][cur.y][cur.key] = true;
			q.push(cur);
		}
	}
	printf("The poor student is trapped!\n");
	return ;
}
signed main(void){
	while(~scanf("%d%d",&n,&m)){
		if(n+m==0) break;
		int sx = 0,sy = 0;
		for(int i = 0;i < n;i++){
			scanf("%s",ch[i]);
			for(int j = 0;j < m;j++)
				if(ch[i][j]=='*'){
					sx = i;
					sy = j;
				}
		}
		bfs(sx,sy);
		memset(vis,false,sizeof vis);
	}
	return 0;
}
