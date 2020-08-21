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
const int N = 55;
int n;ll num[N],bit[N];
void build(){
    for(int i = 1;i <= n;++i){
        for(int j = 52;j >= 0;--j){
            if(num[i] & (1ll<<j)){
                if(!bit[j]){
                    bit[j] = num[i];
                    break;
                }
                else num[i] ^= bit[j];
            }
        }
    }
}
signed main(void){
    scanf("%d",&n);for(int i = 1;i <= n;++i) scanf("%lld",num+i);
    build();ll ans = 0;
    for(int i = 52;i >= 0;--i) if((ans^bit[i]) > ans) ans ^= bit[i];
    for(int i = 10;i >= 0;--i) printf("%d%c",bit[i]," \n"[i==0]);
    printf("%lld\n",ans);
    return 0;
}
