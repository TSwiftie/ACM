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
string ch,sh;int n;vector<string>ans;
signed main(void){
    cin >> ch;cin >> n;
    for(int i = 1;i <= n;++i){
        cin >> sh;
        if(SZ(sh)!=SZ(ch)) continue;
        bool flg = true;
        for(int j = 0;j < SZ(ch);++j){
            if(ch[j]!='*' && ch[j]!=sh[j]) { flg = false;break; }
        }
        if(flg) ans.emplace_back(sh);
    }
    cout << ans.size() << endl;
    for(string &str : ans) cout << str << endl;
    return 0;
}
