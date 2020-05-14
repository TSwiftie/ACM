/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 14 May 2020 03:41:16 PM CST
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
const int dir[4][2] = {0,1,1,0,-1,0,0,-1};
int n, m, k;
vector<pii> v;
set<pii> s;
char mat[20][20];
inline bool judge(int x,int y){
	if(x >= 1 && x <= n && y >= 1 && y <= m && mat[x][y]=='.') return true;
	return false;
}
void dfs(int dep){
	if(dep==k) return ;
	for(int i = 0;i < SZ(v);i++)
		for(int j = 0;j < 4;j++){
			int cx = v[i].first,cy = v[i].second;
			int x = cx,y = cy;
			int tx = x + dir[j][0],ty = y + dir[j][1];
			while(judge(tx,ty)){
				x = tx,y = ty;
				tx += dir[j][0],ty += dir[j][1];
			}
			if(s.count({x,y})){
				puts("YES");
				exit(0);
			}
			v[i] = {x,y};
			swap(mat[x][y],mat[cx][cy]);
			dfs(dep+1);
			v[i] = {cx,cy};
			swap(mat[x][y],mat[cx][cy]);
		}
}
signed main(void){
	IOS;
	cin >> m >> n >> k;
	for(int i = 1;i <= n;i++) cin >> (mat[i]+1);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(mat[i][j]=='R') v.push_back({i,j});
			if(mat[i][j]=='D') s.insert({i,j}),mat[i][j] = '.';
		}
	dfs(0);
	puts("NO");
	return 0;
}
