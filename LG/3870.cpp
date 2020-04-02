/************************************************************
	> File Name: 3870.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Thu 02 Apr 2020 02:52:01 PM CST
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
const int N = 1e6+10;
struct SegTree{
	int sum[N<<2],add[N<<2];
	void build(int o,int L,int R){
		if(L==R){
			sum[o] = 0;
			return ;
		}
		int mid = (L+R)>>1;
		build(lc,L,mid);
		build(rc,mid+1,R);
	}
	void pushdown(int o,int L,int mid,int R){
		if(add[o]){
			sum[lc] = mid-L+1-sum[lc];
			sum[rc] = R-mid-sum[rc];
			add[lc] ^= 1;
			add[rc] ^= 1;
			add[o] = 0;
		}
	}
	void update(int o,int L,int R,int l,int r){
		if(r < L || R < l) return ;
		if(l <= L && R <= r){
			sum[o] = R-L+1-sum[o];
			add[o] ^= 1;
			return ;
		}
		int mid = (L+R)>>1;
		pushdown(o,L,mid,R);
		update(lc,L,mid,l,r);
		update(rc,mid+1,R,l,r);
		sum[o] = sum[lc] + sum[rc];
	}
	int query(int o,int L,int R,int l,int r){
		if(r < L || R < l) return 0;
		if(l <= L && R <= r) return sum[o];
		int mid = (L+R)>>1;
		pushdown(o,L,mid,R);
		return query(lc,L,mid,l,r)+query(rc,mid+1,R,l,r);
	}
}seg;
int n, m;
int op, a, b;
signed main(void){
	scanf("%d%d",&n,&m);
	seg.build(1,1,n);
	while(m--){
		scanf("%d%d%d",&op,&a,&b);
		if(op==0) seg.update(1,1,n,a,b);
		else printf("%d\n",seg.query(1,1,n,a,b));
	}
	return 0;
}
