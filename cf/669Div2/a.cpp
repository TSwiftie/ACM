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
int t,n,a[N];vi ans;
signed main(void){
    for(scanf("%d",&t);t--;){
        int cnt0 = 0;scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%d",a+i);
            if(!a[i]) ++cnt0;
        }
        int cnt1 = n-cnt0;
        if(cnt0 >= n/2){
            printf("%d\n",cnt0);
            for(int i = 1;i <= cnt0;++i) printf("0%c"," \n"[i==cnt0]);
        }else{
            printf("%d\n",cnt1-cnt1%2);
            for(int i = 1;i <= cnt1-cnt1%2;++i) printf("1%c"," \n"[i==cnt1-cnt1%2]);
        }
    }
    return 0;
}
