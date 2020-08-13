#include <algorithm>
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
const int N = 1e5+10;
int l[N],r[N],n,k;
void solve(){
    scanf("%d%d",&n,&k);for(int i = 1;i <= n;++i) scanf("%d%d",l+i,r+i);
    for(int i = 2;i <= n;++i){
        int low = max(0,l[i-1]-k),up = r[i-1] + k;
        l[i] = max(l[i],low);r[i] = min(r[i],up);
        if(l[i] > r[i]){ printf("NO\n");return; }
    }
    printf("YES\n");
    vi ans;ans.push_back(l[n]);
    for(int i = n-1;i >= 1;--i){
        int tmp = ans.back();
        if(tmp >= l[i] && tmp <= r[i]) ans.push_back(tmp);
        else if(tmp > r[i]) ans.push_back(r[i]);
        else if(tmp < l[i]) ans.push_back(l[i]);
    }
    for(int i = n-1;i >= 0;--i) printf("%d%c",ans[i]," \n"[i==0]);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
