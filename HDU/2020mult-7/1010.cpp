#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define int long long
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
const int dir[8][2] = {1,0,0,1,-1,0,0,-1,1,1,-1,-1,1,-1,-1,1};
map<pii,bool>mp;int res = 0,lim;
int check(int x,int y){ return x>=1&&y>=1&&__gcd(x,y)>1; }
void dfs(int x,int y){
    ++lim;if(lim>500) return;
    mp[pii(x,y)] = true;
    int ans = 1;
    for(int i=0;i<8;++i){
        int dx = x+dir[i][0],dy = y+dir[i][1];
        if(check(dx,dy)){
            ++ans;
            if(!mp[pii(dx,dy)]) dfs(dx,dy);
        }
    }
    res += ans;
}
void solve(){
    int x, y;
    scanf("%lld%lld",&x,&y);lim = 0;mp.clear();
    int cnt = 1,res = 1;
    mp[pii(x,y)] = true;
    for(int i=0;i<8;++i){
        int dx = x+dir[i][0],dy = y+dir[i][1];lim = 0;
        if(check(dx,dy)){
            ++cnt,++res;
            if(!mp[pii(dx,dy)]) dfs(dx,dy);
        }
        if(lim>500){ printf("0/1\n");return; }
    }
    int g = __gcd(res,cnt);
    printf("%lld/%lld\n",cnt/g,res/g);
}
signed main(void){
    int t;for(scanf("%lld",&t);t--;) solve();
    return 0;
}
