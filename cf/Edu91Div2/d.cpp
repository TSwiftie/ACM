/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月17日 星期五 10时05分09秒
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
ll a[N], b[N];
signed main(void){
    IOS;
    int n, m, k;
    ll x, y;
    cin >> n >> m >> x >> k >> y;
    for(int i = 0;i < n;++i) cin >> a[i];
    for(int i = 1;i <= m;++i) cin >> b[i];
    ll cost = 0;
    int idx = 0;
    for(int i = 1;i <= m+1;++i){
        int st = idx;
        ll p = -1;
        while(idx <= n && a[idx]!=b[i]) p = max(p,a[idx++]);
        if(idx > n) return cout << -1, 0;
        int len = idx - st;
        if(p > b[i-1] && p > b[i]){
            if(len < k) return cout << -1, 0;
            cost += x;
            len -= k;
        }
        if(1ll * y * k <= x) cost += 1LL*y*len;
        else cost += 1ll*x*(len/k)+y*(len%k);
        ++idx;
    }
    cout << cost;
    return 0;
}
