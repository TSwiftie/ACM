/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 17 May 2020 01:46:48 PM CST
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
const int N = 1e5+10;
ll a[N],p;
struct SegTree{
	LL tr[N<<2],add[N<<2],mul[N<<2],tok[N<<2];
	void build(int o,int L,int R){
		if(L==R){
			tr[o] = a[L];
			add[o] = 0;
			mul[o] = 1;
			tok[o] = -1;
			return ;
		}
		int mid = (L+R)>>1;
		build(lc,L,mid);
		build(rc,mid+1,R);
		tr[o] = (tr[lc] + tr[rc])%p;
	}
	void pushdown(int o,int L,int mid,int R){
		if(tok[o]!=-1){
			tok[lc] = tok[rc] = tok[o];
			tr[lc] = (mid-L+1)*tok[o]%p;
			tr[rc] = (R-mid)*tok[o]%p;
			tok[o] = -1;
		}
	}
	void Add(int o,int L,int R,int l,int r,ll k){
		if(R < l || r < L) return ;
		if(l <= L && R <= r){
			tr[o] = (tr[o] + (r-l+1)*k%p)%p;
			add[o] = (add[o] + k)%p;
			return ;
		}
		int mid = (L+R)>>1;
		pushdown(o,L,mid,R);
		Add(lc,L,mid,l,r,k);
		Add(rc,mid+1,R,l,r,k);
		tr[o] = (tr[lc] + tr[rc])%p;
	}
}seg;
signed main(void){
	return 0;
}
