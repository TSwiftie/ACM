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
const int N = 6e5+10;
string s;int n;
signed main(void){
    IOS;int t;for(cin >> t;t--;){
        cin >> n >> s;
        bool a = false,b = false;
        for(int i = 0;i < n;++i){
            if(s[i]=='<') a = true;
            if(s[i]=='>') b = true;
        }
        if(a && b){
            int ans = 0;s += s[0];
            for(int i = 0;i < n;++i) if(s[i]=='-' || s[i+1]=='-') ++ans;
            cout << ans << endl;
        }else cout << n << endl;
    }
    return 0;
}
