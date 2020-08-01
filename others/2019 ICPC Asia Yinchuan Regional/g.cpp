/************************************************************
	> File Name: g.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 01 Aug 2020 09:36:15 PM CST
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
    void pushdown(int o,int L,int mid,int R){
        lazy[lc] += lazy[o];
        lazy[rc] += lazy[o];
        tr[lc] += lazy[o];
        tr[rc] += lazy[o];
        lazy[o] = 0;
    }
    void build(int o,int L,int R){
        if(L==R){ tr[o] = lazy[o] = 0;return ; }
        int mid = (L+R)>>1;
        build(lc,L,mid);build(rc,mid+1,R);
        tr[o] = max(tr[lc],tr[rc]);
    }
    void update(int o,int L,int R,int l,int r,int k){
        if(r < L || R < l) return ;
        if(l <= L && R <= r){ tr[o] += k;lazy[o] += k;return ; }
        int mid = (L+R)>>1;
        pushdown(o,L,mid,R);
        update(lc,L,mid,l,r,k);update(rc,mid+1,R,l,r,k);
        tr[o] = max(tr[lc],tr[rc]);
    }
    int query(int o,int L,int R,int l,int r){
        if(r < L || R < l) return 0;
        if(l <= L && R <= r) return tr[o];
        int mid = (L+R)>>1;
        pushdown(o,L,mid,R);
        return max(query(lc,L,mid,l,r),query(rc,mid+1,R,l,r));
    }
}seg[4];
string op;
int n, q, l, r, x;
signed main(void){
    IOS;
    cin >> n >> q;
    for(int i = 0;i < 4;++i) seg[i].build(1,1,n);
    while(q--){
        cin >> op >> l >> r;
        if(op=="MULTIPLY"){
            cin >> x;
            int cnt = 0;
            while(x%2==0){
                ++cnt;
                x /= 2;
            }
            if(cnt) seg[0].update(1,1,n,l,r,cnt);
            cnt = 0;
            while(x%3==0){
                ++cnt;
                x /= 3;
            }
            if(cnt) seg[1].update(1,1,n,l,r,cnt);
            cnt = 0;
            while(x%5==0){
                ++cnt;
                x /= 5;
            }
            if(cnt) seg[2].update(1,1,n,l,r,cnt);
            cnt = 0;
            while(x%7==0){
                ++cnt;
                x /= 7;
            }
            if(cnt) seg[3].update(1,1,n,l,r,cnt);
        }else if(op=="MAX"){
            int a2 = seg[0].query(1,1,n,l,r);
            int a3 = seg[1].query(1,1,n,l,r);
            int a5 = seg[2].query(1,1,n,l,r);
            int a7 = seg[3].query(1,1,n,l,r);
            cout << "ANSWER " << max(a2,max(a3,max(a5,a7))) << endl;
        }
    }
    return 0;
}
