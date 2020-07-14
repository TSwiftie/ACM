/************************************************************
	> File Name: 4588.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 16时30分08秒
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
int mod;
struct SegTree{
    int tr[N<<3];
    void build(int o,int L,int R){
        if(L==R){
            tr[o] = 1;
            return ;
        }
        int mid = (L+R)>>1;
        build(lc,L,mid);
        build(rc,mid+1,R);
        tr[o] = tr[lc] * tr[rc] % mod;
    }
    void update(int o,int L,int R,int pos,int val){
        if(L==R){
            tr[o] = val;
            return ;
        }
        int mid = (L+R)>>1;
        if(pos <= mid) update(lc,L,mid,pos,val);
        else update(rc,mid+1,R,pos,val);
        tr[o] = tr[lc] * tr[rc] % mod;
    }
}seg;
signed main(void){
    IOS;
    int t;
    for(cin >> t;t--;){
        int n;
        cin >> n >> mod;
        seg.build(1,1,n);
        for(int i = 1;i <= n;++i){
            int opt,m;
            cin >> opt >> m;
            if(opt==1){
                seg.update(1,1,n,i,m);
                cout << seg.tr[1] << endl;
            }else{
                seg.update(1,1,n,m,1);
                cout << seg.tr[1] << endl;
            }
        }
    }
    return 0;
}
