/************************************************************
	> File Name: 6555.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月15日 星期三 09时53分28秒
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
signed main(void){
    IOS;
    int t;
    cin >> t;
    for(int cas = 1;cas <= t;++cas){
        ll n,ans = 0;
        cin >> n;
        for(ll l = 1,r;l <= n;l = r+1){
            r = n/(n/l);
            ll tmp = (n/l)*(r-l+1)%2;
            if(tmp==0&&ans==0) ans = 0;
            else if(tmp==0&&ans==1) ans = 1;
            else if(tmp==1&&ans==0) ans = 1;
            else if(tmp==1&&ans==1) ans = 0;
        }
        cout << "Case " << cas << ": ";
        if(ans) cout << "odd" << endl;
        else cout << "even" << endl;
    }
    return 0;
}
