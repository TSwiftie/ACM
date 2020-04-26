/************************************************************
	> File Name: Tu.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 26 Apr 2020 01:58:27 PM CST
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
const int N = 1e5+10;
struct Point{
	double x,y;
}s[N];
double Area(const Point &a,const Point &b,const Point &c){
	return (a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x)/2;
}
double Dis(const Point &a,const Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(const Point &a,const Point &b){
	return a.x < b.x;
}
double Solve(int l,int r,int flag){
	int id = -1;
	double Max = 0,lenl = Dis(s[l],s[r]),len;
	for(int i = l+1;i < r;i++){
		double area = Area(s[l],s[r],s[i])*flag;
		if(area > Max){
			Max = area;
			id = i;
			len = Dis(s[l],s[i])+Dis(s[i],s[r])-lenl;
		}
	}
	if(id==-1) return 0;
	return Solve(l,id,flag)+Solve(id,r,flag)+len;
}
signed main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lf%lf",&s[i].x,&s[i].y);
	sort(s+1,s+1+n,cmp);
	printf("%.2lf\n",Solve(1,n,1)+Solve(1,n,-1)+Dis(s[1],s[n])*2);
	return 0;
}
