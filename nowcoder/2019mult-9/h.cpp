/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 20 Jul 2020 11:28:36 AM CST
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
const int N = 2e5+10;
int n, q, m = 1e5, h[N], ra[N];
ll sum[N];
int root[N],tot;
struct Tree{
    int ls, rs;
    ll cnt, v;
}tr[N*100];
int build(int l,int r){
    int o = ++tot;
    if(l==r){
        tr[o].cnt = 0;
        return o;
    }
    int mid = (l+r)>>1;
    tr[o].ls = build(l,mid);
    tr[o].rs = build(mid+1,r);
    tr[o].cnt = tr[tr[o].ls].cnt + tr[tr[o].rs].cnt;
    return o;
}
int insert(int now,int l,int r,int x){
    int o = ++tot;
    tr[o] = tr[now];
    if(l==r){
        ++tr[o].cnt;
        tr[o].v = tr[o].cnt * l;
        return o;
    }
    int mid = (l+r)>>1;
    if(x <= mid) tr[o].ls = insert(tr[now].ls,l,mid,x);
    else tr[o].rs = insert(tr[now].rs,mid+1,r,x);
    tr[o].cnt = tr[tr[o].ls].cnt + tr[tr[o].rs].cnt;
    tr[o].v = tr[tr[o].ls].v + tr[tr[o].rs].v;
    return o;
}
ll query(int p,int q,int L,int R,int l,int r){
    if(l <= L && R <= r) return tr[p].v - tr[q].v;
    int mid = (L+R)>>1;
    ll ans = 0;
    if(l <= mid) ans += query(tr[p].ls,tr[q].ls,L,mid,l,r);
    if(r > mid) ans += query(tr[p].rs,tr[q].rs,mid+1,R,l,r);
    return ans;
}
ll query2(int p,int q,int L,int R,int l,int r){
    if(l <= L && R <= r) return tr[p].cnt - tr[q].cnt;
    int mid = (L+R)>>1;
    ll ans = 0;
    if(l <= mid) ans += query2(tr[p].ls,tr[q].ls,L,mid,l,r);
    if(r > mid) ans += query2(tr[p].rs,tr[q].rs,mid+1,R,l,r);
    return ans;
}
ld ask(int l,int r,ld h){
    ld sum = 0,rsum = 0;
    if(floor(h) >= 1) sum = query(root[r],root[l-1],1,m,1,int(h));
    if(int(h+1) <= m) rsum = query2(root[r],root[l-1],1,m,int(h+1),m);
    ld ans = sum + rsum * h;
    return ans;
}
signed main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(15);
    cin >> n >> q;
    root[0] = build(1,m);
    for(int i = 1;i <= n;++i){
        cin >> h[i];
        sum[i] = sum[i-1] + h[i];
        root[i] = insert(root[i-1],1,m,h[i]);
    }
    while(q--){
        int ll,rr;
        ld x,y;
        cin >> ll >> rr >> x >> y;
        ld l = 0,r = 1e5,cur = ld(sum[rr]-sum[ll-1])*(y-x)/y;
        for(int i = 1;i <= 60;++i){
            ld mid = (l+r)/2;
            if(ask(ll,rr,mid) >= cur) r = mid;
            else l = mid;
        }
        cout << l << endl;
    }
    return 0;
}
