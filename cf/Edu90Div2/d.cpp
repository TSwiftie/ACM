/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 26 Jun 2020 04:20:30 PM CST
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
mt19937 rnd(time(0));
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
int a[N];
signed main(void){
    IOS;
    int t,n;
    for(cin >> t;t--;){
        cin >> n;
        int ttl = 0,sm = 0,mx = 0,u,mn[2];
        mn[0] = 0;mn[1] = 1e18;
        for(int i = 1,k;i <= n;++i){
            cin >> k;
            ttl += k*(i%2);
            u = !(i%2)*2 - 1;
            sm += k*u;
            mn[i%2] = min(mn[i%2],sm);
            mx = max(mx,sm-mn[i%2]);
        }
        cout << ttl + mx << endl;
    }
    return 0;
}
