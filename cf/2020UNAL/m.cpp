#include <algorithm>
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
vi pos[30];int n;string str,a;
signed main(void){
    IOS;cin >> str;for(int i = 0;i < SZ(str);++i) pos[str[i]-'a'].push_back(i);
    cin >> n;
    for(int i = 1,len,cnt;i <= n;++i){
        len = cnt = 0;cin >> a;
        for(int j = 0;j < SZ(a);++j){
            if(pos[a[j]-'a'].empty() || pos[a[j]-'a'].back() < len) break;
            len = *(lower_bound(all(pos[a[j]-'a']),len))+1;
            ++cnt;
        }
        if(cnt==0) cout << "IMPOSSIBLE" << endl;
        else cout << a.substr(0,cnt) << endl;
    }
    return 0;
}
