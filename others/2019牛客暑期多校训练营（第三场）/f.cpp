/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 03 Aug 2020 02:59:10 PM CST
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
const int N = 505;
ll T,n,m,a[N][N],f1[N],f2[N],ans,q1[N],q2[N];
signed main(void){
    for(scanf("%lld",&T);T--;){
        scanf("%lld%lld",&n,&m);ans = 0;
        for(ll i = 1;i <= n;++i)
            for(ll j = 1;j <= n;++j)
                scanf("%lld",&a[i][j]);
        for(ll i = 1;i <= n;++i){
            for(ll j = 1;j <= n;++j) f1[j] = f2[j] = a[i][j];
            for(ll j = i;j <= n;++j){
                for(ll k = 1;k <= n;++k) f1[k] = max(f1[k],a[j][k]),f2[k] = min(f2[k],a[j][k]);
                if((j-i+1)*n<ans) continue;
                ll l1 = 1,l2 = 1,r1 = 0,r2 = 0;
                for(ll k = 1,w = 1;k <= n;++k){
                    while(l1<=r1&&f1[k]>=f1[q1[r1]]) --r1;
                    q1[++r1] = k;
                    while(l2<=r2&&f2[k]<=f2[q2[r2]]) --r2;
                    q2[++r2] = k;
                    while(w<=k&&f1[q1[l1]]-f2[q2[l2]]>m){
                        ++w;
                        while(l1<=r1&&q1[l1]<w) ++l1;
                        while(l2<=r2&&q2[l2]<w) ++l2;
                    }
                    if((j-i+1)*(n-w+1)<ans) break;
                    if(w<=k) ans = max(ans,(j-i+1)*(k-w+1));
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
