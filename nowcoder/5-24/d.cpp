/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Mon 25 May 2020 09:50:12 AM CST
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
const int N = 5e5+10;
int n,res[N],id[N],a[N];
struct SegTree{
	int tr[N<<2];
	void build(int o,int L,int R){
		if(L==R){
			tr[o] = 1;
			return ;
		}
		int mid = (L+R)>>1;
		build(lc,L,mid);build(rc,mid+1,R);
		tr[o] = tr[lc] + tr[rc];
	}
	void update(int o,int L,int R,int pos){
		if(L==R){
			tr[o] = 0;
			return ;
		}
		int mid = (L+R)>>1;
		if(pos <= mid) update(lc,L,mid,pos);
		else update(rc,mid+1,R,pos);
		tr[o] = tr[lc] + tr[rc];
	}
	int query(int o,int L,int R,int k){
		if(L==R) return L;
		int mid = (L+R)>>1;
		if(tr[lc] >= k) return query(lc,L,mid,k);
		else return query(rc,mid+1,R,k-tr[lc]);
	}
}seg;
signed main(void){
	scanf("%d",&n);
	seg.build(1,1,n);
	for(int i = 1;i <= n;i++) scanf("%d%d",id+i,a+i);
	for(int i = n;i >= 1;i--){
		int pos = seg.query(1,1,n,id[i]);
		res[pos] = a[i];
		seg.update(1,1,n,pos);
	}
	for(int i = 1;i <= n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
