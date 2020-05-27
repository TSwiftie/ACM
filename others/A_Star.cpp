#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>
using namespace std;
const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
const int N = 1e3+10;
struct Node;
int g(const Node &);
int h(const Node &);
int f(const Node &);
bool cmp(const Node &,const Node &);
char mp[N][N];
int pre[N][N];
bool vis[N][N];
struct Node{
	int x,y,step;
};
int n,m;
Node st,ed;
int g(const Node &tmp){
	return tmp.step;
}
int h(const Node &tmp){
	return abs(tmp.x-ed.x)+abs(tmp.y-ed.y);
}
int f(const Node &tmp){
	return g(tmp)+h(tmp);
}
int id(int x,int y){
	return (x-1)*m+y;
}
pair<int,int> rid(int x){
	return make_pair((int)ceil(1.0*x/m),x%m);
}
bool cmp(const Node &a,const Node &b){
	return f(a) > f(b);
}
bool judge(const Node &tmp){
	if(tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > m)
		return false;
	if(mp[tmp.x][tmp.y]=='#'||vis[tmp.x][tmp.y]) return false;
	return true;
}
void PrintPath(int x,int y){
	if(x==st.x&&y==st.y){
		printf("(%d,%d)\n",x,y);
		return ;
	}
	pair<int,int> cur = rid(pre[x][y]);
	PrintPath(cur.first,cur.second);
	printf("(%d,%d)\n",x,y);
}
void A_star(){
	priority_queue<Node, vector<Node>, decltype(cmp) *> q(cmp);
	q.push(st);
	vis[st.x][st.y] = true;
	while(q.size()){
		Node now = q.top();
		q.pop();
		if(now.x==ed.x&&now.y==ed.y){
			printf("步数为:%d\n",now.step);
			PrintPath(now.x,now.y);
			return ;
		}
		for(int i = 0;i < 4;i++){
			Node cur = now;
			cur.x += dir[i][0];
			cur.y += dir[i][1];
			cur.step++;
			if(judge(cur)){
				q.push(cur);
				vis[cur.x][cur.y] = true;
				pre[cur.x][cur.y] = id(now.x,now.y);
			}
		}
	}
}
signed main(void){
	printf("请输入地图大小(N<=1000,M<=1000):");
	scanf("%d%d",&n,&m);
	printf("请输入地图(\".\"表示空地,\"#\"表示障碍):\n");
	for(int i = 1;i <= n;i++)
		scanf("%s",mp[i]+1);
	printf("请指定起点:");
	scanf("%d%d",&st.x,&st.y);
	st.x,st.y;
	st.step = 0;
	printf("请指定终点:");
	scanf("%d%d",&ed.x,&ed.y);
	ed.x,ed.y;
	A_star();
	return 0;
}
