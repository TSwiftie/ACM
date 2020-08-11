/************************************************************
	> File Name: SegTree.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 11 Aug 2020 10:44:57 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
//#define int long long
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long double ld;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int N = 1e5+10;
struct SegTree{
    int tr[N<<2],lazy[N<<2];
    void build(int o,int L,int R){
        if(L==R){ tr[o] = lazy[o] = 0;return ; }
        int mid = (L+R)>>1;
        build(o<<1,L,mid);build(o<<1|1,mid+1,R);
        tr[o] = tr[o<<1] + tr[o<<1|1];
    }
    void pushdown(int o,int L,int mid,int R){
        lazy[o<<1] += lazy[o];lazy[o<<1|1] += lazy[o];
        tr[o<<1] += (mid-L+1)*lazy[o];tr[o<<1|1] += (R-mid)*lazy[o];
        lazy[o] = 0;
    }
    void update(int o,int L,int R,int l,int r,int val){
        if(R < l || r < L) return ;
        if(l <= L && R <= r){ tr[o]+=(R-L+1)*val;lazy[o]+=val;return ; }
        int mid = (L+R)>>1;pushdown(o,L,mid,R);
        update(o<<1,L,mid,l,r,val);update(o<<1|1,mid+1,R,l,r,val);
        tr[o] = tr[o<<1] + tr[o<<1|1];
    }
    int query(int o,int L,int R,int l,int r){
        if(R < l || r < L) return 0;
        if(l <= L && R <= r) return tr[o];
        int mid = (L+R)>>1;pushdown(o,L,mid,R);
        return query(o<<1,L,mid,l,r) + query(o<<1|1,mid+1,R,l,r);
    }
}seg;
signed main(void){
    return 0;
}
