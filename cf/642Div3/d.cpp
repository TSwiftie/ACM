/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sat 16 May 2020 09:13:02 AM CST
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
const int N = 2e5+10;
struct node{
	int l,r;
	node(){}
	node(int _l,int _r): l(_l),r(_r) {}
	bool operator<(const node &a) const{
		if((r-l+1)==(a.r-a.l+1))
			return l > a.l;
		return (r-l+1) < (a.r-a.l+1);
	}
};
int a[N];
signed main(void){
	int t;
	for(scanf("%d",&t);t--;){
		int n,cnt = 0;
		scanf("%d",&n);
		priority_queue<node>q;
		q.push(node(1,n));
		while(q.size()){
			node u = q.top();
			q.pop();
			if(u.l==u.r){
				a[u.l] = ++cnt;
				continue;
			}else{
				int mid = (u.l+u.r)>>1;
				a[mid] = ++cnt;
				if(u.l <= mid-1) q.push(node(u.l,mid-1));
				if(mid+1 <= u.r) q.push(node(mid+1,u.r));
			}
		}
		for(int i = 1;i <= n;i++)
			printf("%d%c",a[i]," \n"[i==n]);
	}
	return 0;
}
