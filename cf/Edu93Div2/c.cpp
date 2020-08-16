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
char ch[N];int n, s[N];map<int,int>mp;
signed main(void){
    int t;for(scanf("%lld",&t);t--;){
        scanf("%lld%s",&n,ch+1);
        //sum[r]-sum[l-1]=r-l+1;
        //sum[r]=r-l+1+sum[l-1];
        //sum[r]-r=sum[l-1]-l+1;
        int ans = 0;
        for(int i = 1;i <= n;++i){
            s[i] = s[i-1] + (ch[i]-'0');
            ++mp[s[i-1]-i+1];
            ans += mp[s[i]-i];
        }
        printf("%lld\n",ans);mp.clear();
    }
    return 0;
}
