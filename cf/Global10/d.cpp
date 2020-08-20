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
void solve(){
    int n, ans = 0,cnt = 0;string s;cin >> n >> s;
    while(SZ(s) && s[0]==s.back()){ ++cnt;s.pop_back(); }
    if(s.empty()){
        if(cnt <= 2){ cout << "0" << endl;return; }
        if(cnt==3){ cout << "1" << endl;return; }
        cout << (cnt+2)/3 << endl;
        return;
    }
    s.push_back('$');
    for(int i = 0;i < SZ(s);++i){
        ++cnt;
        if(s[i]!=s[i+1]){ ans += cnt/3;cnt = 0; }
    }
    cout << ans << endl;
}
signed main(void){
    IOS;int _;for(cin >> _;_--;) solve();
    return 0;
}
