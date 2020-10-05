#include <algorithm>
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
#define lowbit()x) (x&-x)
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
const int N = 1e5+10;
int K, n, tk[N], base[N];
int dfs(int pos){
    if(pos%2==0){
        if(base[pos]) return tk[pos/2];
        else return dfs(pos-1);
    }
    return base[pos] * tk[pos/2] + dfs(pos-1);
}
signed main(void){
    cin >> n >> K;
    tk[0] = 1;
    for(int i = 1;;++i){
        tk[i] = tk[i-1] * K;
        if(tk[i] > n) break;
    }
    int tn = n;base[0] = 0;
    while(tn > 0){ base[++base[0]] = tn%K;tn = tn/K; }
    cout << dfs(base[0]) << endl;
    return 0;
}
