/************************************************************
	> File Name: 1257.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 26 Apr 2020 10:57:49 AM CST
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
const int N = 2e5+10;
struct Point{
	double x,y;
}p[N],pt[N];
bool cmp(const Point &a,const Point &b){
	return a.x==b.x ? a.y<b.y : a.x<b.x;
}
bool cmpy(const Point &a,const Point &b){
	return a.y < b.y;
}
inline double dis(const Point &a,const Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double ClosestPair(int l,int r){
	if(l==r) return INF;
	if(l+1==r) return dis(p[l],p[r]);
	int mid = (l+r)>>1;
	Point pm = p[mid];
	double d = min(ClosestPair(l,mid),ClosestPair(mid+1,r));
	int k = 0;
	for(int i = l;i <= r;i++)
		if(fabs(pm.x-p[i].x) <= d)
			pt[++k] = p[i];
	sort(pt+1,pt+1+k,cmpy);
	for(int i = 1;i < k;i++)
		for(int j = i+1;j <= k && fabs(pt[j].y-pt[i].y) < d;j++)
			d = min(d,dis(pt[i],pt[j]));
	return d;
}
signed main(void){
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,cmp);
	printf("%.4lf\n",ClosestPair(1,n));
	return 0;
}
