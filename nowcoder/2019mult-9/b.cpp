/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 20 Jul 2020 09:33:13 AM CST
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
const ll p = 1e9+7;
ll b, c, w;
struct num {  //建立一个复数域
  ll x, y;
};

num mul(num a, num b, ll p) {  //复数乘法
  num ans = {0, 0};
  ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
  ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
  return ans;
}

ll binpow_real(ll a, ll b, ll p) {  //实部快速幂
  ll ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans % p;
}

ll binpow_imag(num a, ll b, ll p) {  //虚部快速幂
  num ans = {1, 0};
  while (b) {
    if (b & 1) ans = mul(ans, a, p);
    a = mul(a, a, p);
    b >>= 1;
  }
  return ans.x % p;
}

ll cipolla(ll n, ll p) {
  n %= p;
  if (p == 2) return n;
  if (binpow_real(n, (p - 1) / 2, p) == p - 1) return -1;
  ll a;
  while (1) {  //生成随机数再检验找到满足非二次剩余的a
    a = rand() % p;
    w = ((a * a % p - n) % p + p) % p;
    if (binpow_real(w, (p - 1) / 2, p) == p - 1) break;
  }
  num x = {a, 1};
  return binpow_imag(x, (p + 1) / 2, p);
}
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%lld%lld",&b,&c);
        ll n = (b*b%p - 4*c%p + p)%p;
        if(n==0){
            if(b/2 * b/ 2 == c) printf("%lld %lld\n",b/2,b/2);
            else printf("-1 -1\n");
            continue;
        }
        ll d = cipolla(n,p);
        if(d==-1){
            printf("-1 -1\n");
            continue;
        }
        ll x = (b+d+p)%p*binpow_real(2,p-2,p);
        x %= p;
        ll y = (b - x + p) % p;
        printf("%lld %lld\n",min(x,y),max(x,y));
    }
    return 0;
}
