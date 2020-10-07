#include <bits/stdc++.h>
#include <ext/rope>
#include <utility>
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
map<int,int>mp;set<pii>e;int p,n;
signed main(void){
    for(scanf("%d",&n);n--;){
        int t, u, v;
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d",&u,&v);
            if(!e.count(make_pair(u, v))){
                p += ++mp[u]==1;
                p += ++mp[v]==1;
                e.insert(make_pair(u, v));
                e.insert(make_pair(v, u));
            }
        }else if(t==2){
            scanf("%d%d",&u,&v);
            if(e.count(make_pair(u, v))){
                p -= --mp[u]==0;
                p -= --mp[v]==0;
                e.erase(make_pair(u, v));
                e.erase(make_pair(v, u));
            }
        }else printf("%d\n",p-SZ(e)/2);
    }
    return 0;
}
