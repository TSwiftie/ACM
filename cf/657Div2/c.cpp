/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 21 Jul 2020 09:16:30 AM CST
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
int n, m, t, ans, sum[N], b[N], x[N], y[N];
signed main(void){
    IOS;
    for(cin >> t;t--;){
        cin >> n >> m;
        ans = 0;
        for(int i = 1;i <= m;++i){
            cin >> x[i] >> y[i];
            b[i] = x[i];
        }
        sort(b+1,b+1+m);
        sum[m+1] = 0;
        for(int i = m;i >= 1;i--) sum[i] = sum[i+1] + b[i];
        if(n <= m) ans = sum[m-n+1];
        for(int i = 1;i <= m;++i){
            int l = lower_bound(b+1,b+m+1,y[i]) - b;
            int ls = m-l+2;
            if(n >= ls) ans = max(ans,sum[l]+(n-ls)*y[i]+(y[i]>x[i]?x[i]:y[i]));
        }
        cout << ans << endl;
    }
    return 0;
}
