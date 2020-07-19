/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 09:24:55 AM CST
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
int n, m;
vi mp_x[N];
int k_y[N];
struct SegTree{
    int tr[N<<4];
    void build(int o,int L,int R){
        if(L==R){
            tr[o] = 0;
            for(int i = 0;i < 3;++i)
                if(L+i*m < N) tr[o] += k_y[L+i*m];
            return ;
        }
        int mid = (L+R)>>1;
        build(lc,L,mid);
        build(rc,mid+1,R);
        tr[o] = max(tr[lc],tr[rc]);
    }
    void update(int o,int L,int R,int pos,int val){
        if(L==R){
            tr[o] += val;
            return ;
        }
        int mid = (L+R)>>1;
        if(pos <= mid) update(lc,L,mid,pos,val);
        else update(rc,mid+1,R,pos,val);
        tr[o] = max(tr[lc],tr[rc]);
    }
}seg;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 0,a,b;i < n;++i){
        scanf("%d%d",&a,&b);
        ++a;++b;
        mp_x[a].push_back(b);
        ++k_y[b];
    }
    seg.build(1,1,1e5+1);
    int ans = 0;
    for(int i = 1;i <= 1e5;++i){
        int res = 0;
        for(int j = 0;j < 3;++j){
            if(i*j+m < N) res += mp_x[i+j*m].size();
            for(int k = 0;i*j+m < N && k < mp_x[i+j*m].size();++k){
                int now = mp_x[i+j*m][k];
                for(int p = 0;p < 3;++p)
                    if(now-p*m > 0)
                        seg.update(1,1,1e5+1,now-p*m,-1);
            }
        }
        res += seg.tr[1];
        ans = max(ans,res);
        for(int j = 0;j < 3;++j)
            for(int k = 0;i+j*m < N && k < mp_x[i+j*m].size();++k){
                int now = mp_x[i+j*m][k];
                for(int p = 0;p < 3;++p)
                    if(now-p*m > 0)
                        seg.update(1,1,1e5+1,now-p*m,1);
            }
    }
    printf("%d\n",ans);
    return 0;
}
