/************************************************************
	> File Name: SegTree.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 16 Mar 2020 02:23:57 PM CST
************************************************************/

#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define range(x) x.begin(),x.end()
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
const int MAXN = 1e5+5;
const int MAXM = 2e5+5;
const int MOD = 1e9+7;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
const double PI = acos(-1.0);
const double EPS = 1e-8;
int a[MAXN];
struct SegTree{
	int tr[MAXN<<2],lazy[MAXN<<2];
	void pushup(int o){
		tr[o] = tr[lc] + tr[rc]; 
	}
	void pushdown(int o,int L,int mid,int R){
		if(lazy[o]){
			lazy[lc] += lazy[o];
			lazy[rc] += lazy[o];
			tr[lc] += (mid-L+1)*lazy[o];
			tr[rc] += (R-mid)*lazy[o];
			lazy[o] = 0;
		}
	}
	void build(int o,int L,int R){
		lazy[o] = 0;
		if(L==R){
			tr[o] = a[L];
			return ;
		}
		int mid = (L+R)>>1;
		build(lc,L,mid);
		build(rc,mid+1,R);
		pushup(o);
	}
	void update(int o,int L,int R,int l,int r,int v){
		if(r < L || l > R) return ;
		if(l <= L && R <= r){
			tr[o] += (R-L+1)*v;
			lazy[o] += v;
			return ;
		}
		int mid = (L+R)>>1;
		pushdown(o,L,mid,R);
		update(lc,L,mid,l,r,v);
		update(rc,mid+1,R,l,r,v);
		pushup(o);
	}
	int query(int o,int L,int R,int l,int r){
		if(r < L || l > R) return 0;
		if(l <= L || R <= r) return tr[o];
		int mid = (L+R)>>1;
		pushdown(lc,L,mid,R);
		return query(lc,L,mid,l,r)+query(rc,mid+1,R,l,r);
	}
}seg;
signed main(void){
	return 0;
}
