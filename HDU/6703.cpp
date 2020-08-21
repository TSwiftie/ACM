/************************************************************
	> File Name: 6703.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月15日 星期三 12时11分17秒
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
//mt19937 rnd(time(0));
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
struct SegTree{
    int mx[N<<2],id[N<<2];
    void pushup(int o){
        mx[o] = max(mx[lc],mx[rc]);
    }
    void build(int o,int L,int R,int *A){
        if(L==R){ id[o] = mx[o] = A[L];return; }
        int mid = (L+R)>>1;
        build(lc,L,mid,A);build(rc,mid+1,R,A);
        pushup(o);
    }
    void update(int o,int L,int R,int pos,int val){
        if(L==R){ id[o] = mx[o] = val; return ; }
        int mid = (L+R)>>1;
        if(pos <= mid) update(lc,L,mid,pos,val);
        else update(rc,mid+1,R,pos,val);
        pushup(o);
    }
    int query(int o,int L,int R,int l,int r,int val){
        if(L==R) return L;
        int res = INF,mid = (L+R)>>1;
        if(l <= mid && val < mx[lc]) res = query(lc,L,mid,l,r,val);
        if(res!=INF) return res;
        if(r > mid && val < mx[rc]) res = query(rc,mid+1,R,l,r,val);
        return res;
    }
}seg;
pii A[N];
int B[N];
int n, m;
bool cmp(pii a,pii b){ return a.second < b.second; }
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i){
            scanf("%d",&A[i].first);
            A[i].second = i;
        }
        sort(A+1,A+1+n);
        for(int i = 1;i <= n;++i) B[i] = A[i].second;
        sort(A+1,A+1+n,cmp);
        B[++n] = INF;
        seg.build(1,1,n,B);
        int ans = 0;
        while(m--){
            int opt;
            scanf("%d",&opt);
            if(opt==1){
                int t1,pos;
                scanf("%d",&t1);
                pos = t1^ans;
                seg.update(1,1,n,A[pos].first,INF);
            }else{
                int t2,t3,r,k;
                scanf("%d%d",&t2,&t3);
                r = t2^ans;k = t3^ans;
                printf("%d\n",ans = seg.query(1,1,n,k,n,r));
            }
        }
    }
    return 0;
}
