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
using namespace __gnu_cxx;
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
rope<int>s;
signed main(void){
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) s.push_back(i);
    while(m--){
        int l, k;
        scanf("%d%d",&l,&k);
        s = s.substr(l-1,k) + s.substr(0,l-1) + s.substr(l+k-1,n+1-k-l);
    }
    for(auto c : s) printf("%d ",c);
    puts("");
    return 0;
}
