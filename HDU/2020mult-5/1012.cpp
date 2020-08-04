/************************************************************
	> File Name: 1012.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 04 Aug 2020 04:49:31 PM CST
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
const int N = 2e6+10;
const int p = 998244353;
int fac[N];
int ksm(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
signed main(void){
    fac[0] = 1;
    for(int i = 1;i < N;++i) fac[i] = fac[i-1] * i % p;
    int T, n;
    for(cin >> T;T--;){
        cin >> n;
        if(n==1){ cout << 1 << endl; continue; }
        for(int i = 0;i < n/2;++i) cout << "0 ";
        int a = fac[n/2],di = ksm(2,n/2)*a%p;
        di = ksm(di,p-2);
        cout << (a*di%p);
        for(int i = 1;i < n/2;++i){
            a = a*(n/2+i)%p;
            a = a * ksm(i*2,p-2)%p;
            cout << " " << (a*di%p);
        }
        cout << " " << (a*di%p) << endl;
    }
    return 0;
}
