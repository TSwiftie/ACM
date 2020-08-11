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
const int N = 2e5+10;
string s;int ans[N];
vi p[2];
void solve(){
    int n,cnt = 0;cin >> n >> s;
    memset(ans,0,sizeof ans);
    for(int i = 0;i < n;++i){
        if(p['1'-s[i]].size()) { ans[i]=p['1'-s[i]].back();p['1'-s[i]].pop_back(); }
        else ans[i] = ++cnt;
        p[s[i]-'0'].push_back(ans[i]);
    }
    cout << cnt << endl;
    for(int i = 0;i < n;++i)
        cout << ans[i] << ' ';
    cout << endl;p[0].clear();p[1].clear();
}
signed main(void){
    IOS;int t;for(cin >> t;t--;) solve();
    return 0;
}
