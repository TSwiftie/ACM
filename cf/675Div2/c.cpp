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
const char *INPUT = "/home/ts/code/in.in";
const int mod = 1e9+7;
const int N = 1e5+10;
char s[N];int ans;
signed main(void){
    scanf("%s",s);
    int n = strlen(s);
    int p = 1,now = 0;
    for(int i = n-1;i >= 0;--i){
        int cur = 1ll*i*(i+1)/2;
        cur = (cur*p+now)%mod;
        ans = (ans+cur*(s[i]-'0')) % mod;
        now = (now+p*(n-i))%mod;
        p = p*10%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
