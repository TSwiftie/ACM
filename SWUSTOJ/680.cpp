/************************************************************
	> File Name: 680.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 13 May 2020 05:16:06 PM CST
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
struct Line{
	int x1,x2;
	int y1,y2;
}s[20];
int cross(int x1,int y1,int x2,int y2){
	return x1*y2-x2*y1;
}
bool intersection(Line A, Line B){
	if (max(A.x1, A.x2) < min(B.x1, B.x2) || max(A.y1, A.y2) < min(B.y1, B.y2)
		|| max(B.x1, B.x2) < min(A.x1, A.x2) || max(B.y1, B.y2) < min(A.y1, A.y2))
		return false;
 
	int c[4];
	c[0] = cross(A.x2 - A.x1, A.y2 - A.y1, B.x1 - A.x1, B.y1 - A.y1);
	c[1] = cross(A.x2 - A.x1, A.y2 - A.y1, B.x2 - A.x1, B.y2 - A.y1);/*两个分别组合*/
	c[2] = cross(B.x2 - B.x1, B.y2 - B.y1, A.x1 - B.x1, A.y1 - B.y1);
	c[3] = cross(B.x2 - B.x1, B.y2 - B.y1, A.x2 - B.x1, A.y2 - B.y1);
	if (c[0] * c[1] <= 0 && c[2] * c[3] <= 0)	
		return true;
	return false;
}
int f[20];
int find(int x){
	return x==f[x] ? x : f[x] = find(f[x]);
}
signed main(void){
	int n;
	while(~scanf("%d",&n)){
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d%d",&s[i].x1,&s[i].y1,&s[i].x2,&s[i].y2);
			f[i] = i;
		}
		for(int i = 1;i < n;i++)
			for(int j = i+1;j <= n;j++)
				if(intersection(s[i],s[j])){
					int u = find(i),v = find(j);
					f[v] = u;
				}
		int u, v;
		while(~scanf("%d%d",&u,&v)&&u|v){
			int fu = find(u),fv = find(v);
			if(fu==fv) printf("CONNECTED\n");
			else printf("NOT CONNECTED\n");
		}
	}
	return 0;
}
