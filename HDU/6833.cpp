/************************************************************
	> File Name: 6833.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 09 Aug 2020 11:31:06 AM CST
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
const int p = 1e9+7;
const int N = 2e5+10;
int pri[N],mu[N],S1[N],S2[N],tot;
int n, x, k;
bool vis[N];
inline int ksm(int a,int b,int res = 1){
    while(b){
        if(b&1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
inline void init(){
    mu[1] = 1;
    for(int i = 2;i < N;++i){
        if(!vis[i]) pri[++tot] = i,mu[i] = -1;
        S1[i] = (S1[i-1] + mu[i] * ksm(i,x*k+1) % p) % p;
        S2[i] = (S2[i-1] + mu[i] * mu[i] % p * ksm(i,x*k+1) % p) % p;
        for(int j = 1;j <= tot && i*pri[j] < N;++j){
            vis[i*pri[j]] = true;
            if(i%pri[j]==0){
                mu[i*pri[j]] = 0;
                break;
            }
            mu[i*pri[j]] = -mu[i];
        }
    }
}
signed main(void){
    int _;
    for(scanf("%lld",&_);_--;){
    }
    return 0;
}
