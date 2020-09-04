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
int n,root = 1,dis,tmp;
signed main(void){
    IOS;cin >> n;
    cout << root << endl;
    cin >> dis;
    root <<= 1;
    while(dis!=0){
        cout << root << endl;
        cin >> tmp;
        if(tmp==0){ cout <<"! " << root << endl;return 0; }
        if(tmp==2 && root!=1) {
            cout << (root|1) << endl;
            int tt;cin >> tt;
            if(tt==0) { cout << "! " << root << endl; }
        }
        if(tmp > dis) { root|=1;root<<=1;--dis; }
        else dis = tmp,root<<=1;
    }
    return 0;
}
