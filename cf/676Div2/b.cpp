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
const int N = 204;
string s[N];
signed main(void){
    IOS;int t,n;for(cin >> t;t--;){
        cin >> n;for(int i = 0;i < n;++i) cin >> s[i];
        int a1,a2,b1,b2;
        a1 = s[0][1]=='1';b1 = s[n-2][n-1]=='1';
        a2 = s[1][0]=='1';b2 = s[n-1][n-2]=='1';
        if(a1==a2 && b1==b2 && a1==b1){
            cout << 2 << endl;
            printf("1 2\n");
            printf("2 1\n");
        }else if(a1==a2 && b1==b2 && a1!=b1) cout << 0 << endl;
        else if(a1==a2 && b1!=b2){
            printf("1\n");
            if(b1==a1) printf("%d %d\n",n-1,n);
            else if(b2==a1) printf("%d %d\n",n,n-1);
        }
    }
    return 0;
}
