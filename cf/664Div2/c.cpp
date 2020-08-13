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
const int N = 205;
int a[N],b[N],n,m;
signed main(void){
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i) scanf("%d",a+i);
    for(int i = 1;i <= m;++i) scanf("%d",b+i);
    for(int k = 0;k < 512;++k){
        int cnt = 0;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                int tmp = a[i]&b[j];
                if((tmp&k)==tmp){ ++cnt;break; }
            }
        }
        if(cnt==n){ printf("%d\n",k);return 0; }
    }
    return 0;
}
