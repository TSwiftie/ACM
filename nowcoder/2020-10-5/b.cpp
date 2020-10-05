#include <bits/stdc++.h>
#include <cctype>
#include <ext/rope>
#include <set>
#include <unordered_map>
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
const char *INPUT = "/home/ts/code/in.in";
const int N = 3e5+10;
int b[N][300],n;char str[N];
unordered_map<ll, int>num;
signed main(void){
    scanf("%d%s",&n,str+1);
    ll s = 0,ans = 0,a = 0;num[0] = 1;
    for(int i = 1;i <= n;++i){
        if(islower(str[i])) a = str[i]-'a';
        else a = str[i]-'A'+26;
        s ^= 1LL << a;
        for(int j = 0;j < 52;++j)
            if(num.count(s ^ (1LL << j)))
                ans += num[s ^ (1LL << j)];
        if(num.count(s)) ans += num[s];
        ++num[s];
    }
    printf("%lld\n",ans);
    return 0;
}
