/************************************************************
	> File Name: 2335.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 01 Apr 2020 03:56:24 PM CST
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
const int N = 155;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
struct node{
	int x,y;
	int step;
};
int n, m;
int ch[N][N],ans[N][N];
bool vis[N][N];
signed main(void){
	scanf("%d%d",&n,&m);
	queue<node>q;
	node s;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			scanf("%d",&ch[i][j]);
			if(ch[i][j]){
				s.x = i;
				s.y = j;
				s.step = 0;
				q.push(s);
				vis[i][j] = true;
			}
		}
	while(q.size()){
		node ss = q.front();
		q.pop();
		ans[ss.x][ss.y] = ss.step;
		for(int i = 0;i < 4;i++){
			node cc = ss;
			cc.x += dir[i][0];
			cc.y += dir[i][1];
			cc.step++;
			if(cc.x>=1&&cc.x<=n&&cc.y>=1&&cc.y<=m&&!vis[cc.x][cc.y]){
				vis[cc.x][cc.y] = true;
				q.push(cc);
			}
		}
	}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			printf("%d%c",ans[i][j]," \n"[j==m]);
	return 0;
}
