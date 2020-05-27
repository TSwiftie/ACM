#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
const int N = 1e3+10;

//函数和变量声明
struct Node;
//G函数
int g(const Node &);
//H函数
int h(const Node &);
//F函数 F = G + H
int f(const Node &);
//坐标映射成一个整数
int id(int,int);
//将整数变回坐标
pair<int,int> rid(int);
//优先队列比较函数
bool cmp(const Node &,const Node &);
//判断坐标是否合法
bool judge(const Node &);
//打印路径
void PrintPath(int,int);
//A*算法
void A_star();

//地图矩阵
char mp[N][N];
//路径矩阵,pre[i][j]为坐标(i,j)的前一个节点
int pre[N][N];
//是否访问过
bool vis[N][N];
//定义节点
struct Node{
	int x,y,step;
};

//地图大小
int n,m;
//起始节点和终点节点
Node st,ed;

int g(const Node &tmp){//起点到当前点的实际距离
	return tmp.step;
}
int h(const Node &tmp){//当前点到终点的预估距离,使用曼哈顿距离
	return abs(tmp.x-ed.x)+abs(tmp.y-ed.y);
}
int f(const Node &tmp){//F = G + H
	return g(tmp)+h(tmp);
}
int id(int x,int y){//将坐标映射成一个整数
	return (x-1)*m+y;
}
pair<int,int> rid(int x){//反映射
	return make_pair((int)ceil(1.0*x/m),x%m);
}
bool cmp(const Node &a,const Node &b){//优先队列比较函数
	return f(a) > f(b);
}
bool judge(const Node &tmp){//坐标是否合法,不合法条件为超出地图或者已经访问或者是障碍
	if(tmp.x < 1 || tmp.x > n || tmp.y < 1 || tmp.y > m)
		return false;
	if(mp[tmp.x][tmp.y]=='#'||vis[tmp.x][tmp.y]) return false;
	return true;
}
void PrintPath(int x,int y){//递归打印路径
	if(x==st.x&&y==st.y){
		printf("(%d,%d)\n",x,y);
		return ;
	}
	pair<int,int> cur = rid(pre[x][y]);
	PrintPath(cur.first,cur.second);
	printf("(%d,%d)\n",x,y);
}
void A_star(){
	//使用优先队列作为open表,vis数组代替close表
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
		for(int i = 0;i < 4;i++){//从上下四个方向找合法点放入优先队列
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
	char *ch = "*#";
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
