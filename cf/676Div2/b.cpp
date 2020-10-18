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
char s[201][201];int n;
bool check(char x,char y){
    int res = (s[1][2]!=x) + (s[2][1]!=x) + (s[n-1][n]!=y) + (s[n][n-1]!=y);
    if(res <= 2){
        printf("%d\n",res);
        if(s[1][2]!=x) printf("1 2\n");
        if(s[2][1]!=x) printf("2 1\n");
        if(s[n-1][n]!=y) printf("%d %d\n",n-1,n);
        if(s[n][n-1]!=y) printf("%d %d\n",n,n-1);
        return true;
    }
    return false;
}
signed main(void){
    int t;for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i) scanf("%s",s[i]+1);
        if(!check('0','1')) check('1','0');
    }
    return 0;
}
