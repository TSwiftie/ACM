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
int cnt[N];
signed main(void){
    IOS;int n, q, x, cnt2 = 0,cnt4 = 0;char op;
    scanf("%d",&n);for(int i = 1;i <= n;++i){
        scanf("%d",&x);
        cnt2 -= cnt[x]/2;
        cnt4 -= cnt[x]/4;
        ++cnt[x];
        cnt2 += cnt[x]/2;
        cnt4 += cnt[x]/4;
    }
    for(scanf("%d",&q);q--;){
        scanf(" %c %d",&op,&x);
        cnt2 -= cnt[x]/2;
        cnt4 -= cnt[x]/4;
        if(op=='+') ++cnt[x];
        else --cnt[x];
        cnt2 += cnt[x]/2;
        cnt4 += cnt[x]/4;
        if(cnt4 >= 1 && cnt2 >= 4) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
