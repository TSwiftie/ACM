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
const int N = 1e5+10;
const int p = 1e9+7;
int f[N],n,m;
int calc(int x){
    if(x&1) return (x-1)/2%p*x%p;
    else return x/2%p*(x-1)%p;
}
int ksm(int a,int b,int res=1){ for(;b;b>>=1,a = a * a % p) if(b&1) res = res * a % p; return res;}
signed main(void){
    IOS;f[2] = 1;for(int i = 4;i < N;i+=2) f[i] = f[i-2] * calc(i) % p;
    cin >> n >> m;for(int i = 1,x,y;i <= m;++i){ cin >> x >> y; }
    if(n==2*m) cout << f[2*m] << endl;
    else cout << f[2*m] * ksm(n-2*m,2*m+1) << endl;
    return 0;
}
