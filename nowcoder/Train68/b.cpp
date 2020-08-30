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
const int p = 199999;
char ch[N];
int sumi[N],sumj[N],sumk[N];
void solve(){
    scanf("%s",ch);int len = strlen(ch);
    if(len > 6) { puts("0");return; }
    int n = 0;
    for(int i = 0;i < len;++i) n = n*10 + ch[i] - '0';
    if(n >= p) { puts("0");return; }
    printf("%lld\n",sumi[n]);
}
signed main(void){
    sumi[0] = 1;
    for(int i = 1;i <= p;++i) sumk[i] = (sumk[i-1] + i) % p;
    for(int i = 1;i <= p;++i) sumj[i] = (sumj[i-1] + i*sumk[i]%p) % p;
    for(int i = 1;i <= p;++i) sumi[i] = (sumi[i-1] * i % p * sumj[i] % p) % p;
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
