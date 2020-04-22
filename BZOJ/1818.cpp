/************************************************************
	> File Name: 1818.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Wed 22 Apr 2020 10:31:41 AM CST
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
int n,cnt,ans,hsh[100001],tr[100001];
struct point{
	int x,y;
}a[100001];
struct Seg{
	int k,x,y,r;
}s[1000001];
inline bool cmp1(point a,point b){
	return a.x==b.x ? a.y < b.y : a.x < b.x;
}
inline bool cmp2(point a,point b){
	return a.y==b.y ? a.x < b.x : a.y < b.y;
}
inline bool cmp3(Seg a,Seg b){
	return a.y==b.y ? a.k < b.k : a.y < b.y;
}
int find(int x){
	int l = 1,r = n;
	while(l <= r){
		int mid = (l+r)>>1;
		if(hsh[mid] < x) l = mid+1;
		else if(hsh[mid] > x) r = mid-1;
		else return mid;
	}
}
void insert(int k,int l,int r,int t){
	if(!k){
		s[++cnt].x = find(l);s[cnt].r = find(r);s[cnt].y = t;
	}else{
		s[++cnt].x = find(t);s[cnt].y = l;s[cnt].k = 1;
		s[++cnt].x = find(t);s[cnt].y = r;s[cnt].k = -1;
	}
}
void build(){
	sort(a+1,a+1+n,cmp1);
	for(int i = 2;i <= n;i++)
		if(a[i].x==a[i-1].x)
			insert(1,a[i-1].y,a[i].y,a[i].x);
	sort(a+1,a+1+n,cmp2);
	for(int i = 2;i <= n;i++)
		if(a[i].y==a[i-1].y)
			insert(0,a[i-1].x,a[i].x,a[i].y);
}
void update(int o,int v){
	while(o <= n){
		tr[o] += v;
		o += lowbit(o);
	}
}
int ask(int o,int ans = 0){
	while(o){
		ans += tr[o];
		o -= lowbit(o);
	}
	return ans;
}
void work(){
	for(int i = 1;i <= cnt;i++){
		if(!s[i].k) ans += ask(s[i].r-1)-ask(s[i].x);
		else update(s[i].x,s[i].k);
	}
}
signed main(void){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		hsh[i] = a[i].x;
	}
	sort(hsh+1,hsh+1+n);
	build();
	sort(s+1,s+cnt+1,cmp3);
	work();
	printf("%d\n",ans+n);
	return 0;
}
