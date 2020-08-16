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
signed main(void){
    IOS;int t;for(cin >> t;t--;){
        string s;cin >> s;
        int cnt = 0;vi tmp;
        for(int i = 0;i < SZ(s);++i){
            if(s[i]=='1') ++cnt;
            else tmp.push_back(cnt),cnt = 0;
        }
        if(cnt) tmp.push_back(cnt);
        int ans = 0;sort(all(tmp),[](int a,int b){ return a > b; });
        for(int i = 0;i < SZ(tmp);i+=2) ans += tmp[i];
        cout << ans << endl;
    }
    return 0;
}
