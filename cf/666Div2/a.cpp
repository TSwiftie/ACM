#include <cstring>
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
const int N = 1e3+10;
char ch[N];
int buc[30],n,t;
void solve(){
    memset(buc,0,sizeof buc);
    scanf("%d",&n);for(int i = 1;i <= n;++i){
        scanf("%s",ch);
        int len = strlen(ch);
        for(int j = 0;j < len;++j) ++buc[ch[j]-'a'];
    }
    for(int i = 0;i < 26;++i) if(buc[i]%n) { printf("NO\n");return ; }
    printf("YES\n");
}
signed main(void){
    for(scanf("%d",&t);t--;) solve();
    return 0;
}
