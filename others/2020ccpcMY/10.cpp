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
const char *INPUT = "/home/ts/code/in.in";
signed main(void){
    int t;scanf("%d",&t);for(int cas = 1;cas <= t;++cas){
        int n;scanf("%d",&n);
        printf("Case #%d: ",cas);
        if(n&1) printf("1\n");
        else if(n % 4 == 0) printf("2\n");
        else if(n == 6) printf("-1\n");
        else{
            if(n % 3 == 0) printf("2\n");
            else if(n % 3 == 1){
                int a = (n - 1) / 3;
                int b = a - 1,c = a + 2;
                if(__gcd(b, c)==1) printf("3\n");
                else printf("4\n");
            }else if(n % 3 == 2){
                int a = (n + 1) / 3;
                int b = a - 2,c = a + 1;
                if(__gcd(b, c)==1) printf("3\n");
                else printf("4\n");
            }
        }
    }
    return 0;
}
