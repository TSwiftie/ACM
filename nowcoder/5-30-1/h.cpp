/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: 2224273204@qq.com 
	> Created Time: Sun 31 May 2020 11:23:06 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
int n, m, a[N];
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	for(;ch>'9'||ch<'0';ch = getchar()) if(ch=='-') f = -1;
	for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3)+(ch^48);
	return x*f;
}
inline int Lcm(int a,int b){
	return a/__gcd(a,b)*b;
}
struct SegTree{
	int sum[N<<2],lcm[N<<2];
	void pushup(int o){
		sum[o] = sum[lc] + sum[rc];
		lcm[o] = Lcm(lcm[lc],lcm[rc]);
	}
	void build(int o,int L,int R){
		if(L==R){
			sum[o] = lcm[o] = read();
			return ;
		}
		int mid = L+R>>1;
		build(lc,L,mid);build(rc,mid+1,R);
		pushup(o);
	}
	void update(int o,int L,int R,int l,int r,int x){
		if(x%lcm[o]==0) return ;
		if(r < L || R < l) return ;
		if(L==R){
			sum[o] = lcm[o] = __gcd(lcm[o],x);
			return ;
		}
		int mid = L+R>>1;
		update(lc,L,mid,l,r,x);update(rc,mid+1,R,l,r,x);
		pushup(o);
	}
	int query(int o,int L,int R,int l,int r){
		if(r < L || R < l) return 0;
		if(l <= L && R <= r) return sum[o];
		int mid = L+R>>1;
		return query(lc,L,mid,l,r)+query(rc,mid+1,R,l,r);
	}
}seg;
signed main(void){
	n = read(),m = read();
	seg.build(1,1,n);
	for(int i = 1;i <= m;++i){
		int op = read(),l = read(),r = read();
		if(op==1) seg.update(1,1,n,l,r,read());
		else printf("%lld\n",seg.query(1,1,n,l,r));
	}
	return 0;
}
