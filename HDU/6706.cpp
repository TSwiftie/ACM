/************************************************************
	> File Name: 6706.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 08 Aug 2020 05:11:01 PM CST
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
const int N = 6000100;
const int p = 1e9+7;
const int inv6 = 166666668;
int getSum(ll k){
    ll k3 = k*k%p*k%p;
    ll res = (k3-k+p)%p;
    res = res * inv6 % p;
    return res;
}
int sum[N];
bool vis[N];
int prime[N],mu[N];
void init(){
    int cnt = 0;
    mu[1] = sum[1] = 1;
    for(int i = 2;i < N;++i){
        if(!vis[i]){
            prime[cnt++] = i;
            mu[i] = -1;
        }
        sum[i] = (sum[i-1]+mu[i]*i%p+p)%p;
        for(int j = 0;j < cnt && prime[j]*i < N;++j){
            int k = i*prime[j];
            vis[k] = true;
            if(i%prime[j]==0) break;
            mu[k] = -mu[i];
        }
    }
}
unordered_map<int, ll>mp;
ll S(int n){
    if(n < N) return sum[n];
    if(mp[n]) return mp[n];
    ll ans = 1,td,tmp;
    for(int l = 2,r;l <= n;l = r+1){
        r = n/(n/l);
        td = r-l+1;
        td = (r+l)*td/2;
        td %= p;
        tmp = td*S(n/l)%p;
        ans = (ans - tmp + p) % p;
    }
    return mp[n] = ans;
}
signed main(void){
    init();
    int T;
    for(scanf("%d",&T);T--;){
        int n, a, b;
        scanf("%d%d%d",&n,&a,&b);
        ll td,res = 0;
        for(int l = 1,r;l <= n;l = r+1){
            r = n/(n/l);
            td = (S(r) - S(l-1) + p) % p;
            res = (res + getSum(n/l) * td % p) % p;
        }
        printf("%lld\n",res);
    }
    return 0;
}
