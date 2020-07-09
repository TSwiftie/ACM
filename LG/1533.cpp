/************************************************************
	> File Name: 1533.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: jue 09 jul 2020 15:22:04
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
const int N = 3e5+10;
int tr[N<<2],n,m,pos[N],a[N],ans[N];
struct Query{
    int l,r,k,id;
}q[N];
struct numm{
    int v,id;
    bool operator<(const numm &a) const{
        return v < a.v;
    }
}nm[N];
bool cmp(Query a,Query b){
    return pos[a.l]==pos[b.l] ? a.r < b.r : a.l < b.l;
}
int read(){
    int x = 0,f = 1;
    char ch = getchar();
    for(;ch<'0'||ch>'9';ch = getchar()) if(ch=='-') f = -1;
    for(;ch>='0'&&ch<='9';ch = getchar()) x = (x<<1)+(x<<3) + (ch^48);
    return x*f;
}
void pushup(int o){
    tr[o] = tr[lc] + tr[rc];
}
void update(int o,int l,int r,int k,int c){
    if(l==k && r==k){
        tr[o] += c;
        return ;
    }
    int mid = (l+r)>>1;
    if(k <= mid) update(lc,l,mid,k,c);
    else update(rc,mid+1,r,k,c);
    pushup(o);
}
int query(int o,int l,int r,int k){
    if(l==r) return l;
    int mid = (l+r)>>1;
    if(tr[lc] >= k) return query(lc,l,mid,k);
    else return query(rc,mid+1,r,k-tr[lc]);
}
signed main(void){
    n = read();m = read();
    int s = sqrt(n);
    for(int i = 1;i <= n;++i)
        nm[i].v = read(),nm[i].id = i,pos[i] = (i-1)/s+1;
    sort(nm+1,nm+1+n);
    for(int i = 1;i <= n;++i) a[nm[i].id] = i;
    for(int i = 1;i <= m;++i)
        q[i].l = read(),q[i].r = read(),q[i].k = read(),q[i].id = i;
    sort(q+1,q+1+m,cmp);
    for(int i = 1,l = 1,r = 0;i <= m;++i){
        while(r < q[i].r) update(1,1,n,a[++r],1);
        while(r > q[i].r) update(1,1,n,a[r--],-1);
        while(l < q[i].l) update(1,1,n,a[l++],-1);
        while(l > q[i].l) update(1,1,n,a[--l],1);
        ans[q[i].id] = nm[query(1,1,n,q[i].k)].v;
    }
    for(int i = 1;i <= m;++i) printf("%d\n",ans[i]);
    return 0;
}
