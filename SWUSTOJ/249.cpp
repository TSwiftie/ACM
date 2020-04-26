/************************************************************
	> File Name: 249.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 26 Apr 2020 11:59:34 AM CST
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
const int N = 150;
int top,n;
double ans;
struct node{
	double x,y;
}t[N],st[N];
bool cmp(const node &a,const node &b){
	double a1 = atan2(a.y-t[1].y,a.x-t[1].x),a2 = atan2(b.y-t[1].y,b.x-t[1].x);
	return a1==a2 ? a.x < b.x : a1 < a2;
}
double cross(const node &a,const node &b,const node &c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
void Graham(){
	int id = 1;
	top = 0;
	for(int i = 2;i <= n;i++)
		if(t[id].y > t[i].y || (t[id].y==t[i].y && t[id].x > t[i].x)) id = i;
	swap(t[1],t[id]);
	sort(t+2,t+1+n,cmp);
	st[++top] = t[1];
	for(int i = 2;i <= n;i++){
		while(top>=2&&cross(st[top-1],t[i],st[top])>=0) top--;
		st[++top] = t[i];
	}
}
void solve(){
	scanf("%d",&n);
	ans = 0;
	for(int i = 1;i <= n;i++)
		scanf("%lf %lf",&t[i].x,&t[i].y);
	Graham();
	for(int i = 3;i <= top;i++)
		ans += 0.5*fabs(cross(st[1],st[i-1],st[i]));
	printf("%.1lf\n",ans);
}
signed main(void){
	int t;
	for(scanf("%d",&t);t--;)
		solve();
	return 0;
}
