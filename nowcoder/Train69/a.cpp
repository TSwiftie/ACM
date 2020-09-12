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
int t,n;
signed main(void){
    IOS;for(cin >> t;t--;){
        cin >> n;
        ld fen = n*6.0,shi = n*0.5;
        while(fen >= 360) fen -= 360;
        while(shi >= 360) shi -= 360;
        ld ans = fabs(fen-shi);
        if(ans > 180) ans = 360-ans;
        cout << int(ans+0.5) << endl;
    }
    return 0;
}
