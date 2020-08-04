/************************************************************
	> File Name: 1012.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 04 Aug 2020 12:07:46 PM CST
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
const int N = 15e6+10;
const int p = 998244353;
int fac[N],inv[N];
void solve(){
    int n;
    cin >> n;
    if(n==1){ cout << 1 << endl; return ; }
    for(int i = 1;i <= n/2;++i) cout << 0 << " ";
    int ans = (1 - inv[n-1] % p + p)%p;
    for(int i = n/2+1;i <= n;++i){
        cout << ans;
        if(i==n) cout << endl;
        else cout << " ";
    }
}
signed main(void){
    IOS;
    int T;
    fac[0] = fac[1] = 1;
    inv[0] = inv[1] = 1;
    for(int i = 2;i < N;++i){
        //fac[i] = fac[i-1] * i % p;
        inv[i] = (p-p/i)*inv[p%i]%p;
    }
    for(int i = 2;i < N;i += 2) inv[i] = inv[i-2] * inv[i] % p;
    for(cin >> T;T--;) solve();
    return 0;
}
