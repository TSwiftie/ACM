/************************************************************
	> File Name: Chairman_Tree.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 24 May 2020 10:16:45 PM CST
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
const int N = 1e5+100;
int a[N],rk[N],pos[N];
int root[N],cnt,m,n,T;
struct Chairman_Tree{
	struct Node{
		int L,R,val;
	}tr[N*500];
	void init(){
		memset(root,0,sizeof root);
		cnt = 0;
	}
	int buildTo(int l,int r){
		int k = cnt++;
		tr[k].val = 0;
		if(l==r) return k;
		int mid = l+r>>1;
		tr[k].L = buildTo(l,mid);
		tr[k].R = buildTo(mid+1,r);
		return k;
	}
	int update(int P,int l,int r,int ppos,int del){
		int k = cnt++;
		tr[k].val = tr[P].val + del;
		if(l==r) return k;
		int mid = l+r>>1;
		if(ppos <= mid){
			tr[k].L = update(tr[P].L,l,mid,ppos,del);
			tr[k].R = tr[P].R;
		}else{
			tr[k].L = tr[P].L;
			tr[k].R = update(tr[P].R,mid+1,r,ppos,del);
		}
		return k;
	}
	int query_kth(int lt,int rt,int l,int r,int k){
		if(l==r) return a[rk[l]];
		int mid = l+r>>1;
		int num = tr[tr[rt].L].val - tr[tr[lt].L].val;
		if(num >= k) return query_kth(tr[lt].L,tr[rt].L,l,mid,k);
		else return query_kth(tr[lt].R,tr[rt].R,mid+1,r,k-num);
	}
}tree;
bool cmp(int x,int y){
	return a[x] < a[y];
}
signed main(void){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++){
			scanf("%d",a+i);
			rk[i] = i;
		}
		tree.init();
		sort(rk+1,rk+1+n,cmp);
		for(int i = 1;i <= n;i++) pos[rk[i]] = i;
		root[0] = tree.buildTo(1,n);
		for(int i = 1;i <= n;i++)
			root[i] = tree.update(root[i-1],1,n,pos[i],1);
		while(m--){
			int l, r, k;
			scanf("%d%d%d",&l,&r,&k);
			printf("%d\n",tree.query_kth(root[l-1],root[r],1,n,k));
		}
	}
	return 0;
}
