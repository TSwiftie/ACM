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
const char *INPUT = "/home/ts/code/in.in";
const int N = 1e5+10;
const char *mod = "puleyaknoi";
char ch[N];int cnt[30];
bool judge(){
    for(int i = 0;i < 10;++i) if(!cnt[mod[i]-'a']) return false;
    return true;
}
void solve(){
    scanf("%s",ch+1);
    int len = strlen(ch+1),r = 1,ans = INF;
    for(int l = 1;l <= len;++l){
        while(!judge() && r <= len) ++cnt[ch[r++]-'a'];
        if(judge()) ans = min(ans,r-l);
        --cnt[ch[l]-'a'];
    }
    printf("%d\n",ans==INF?-1:ans);
    memset(cnt,0,sizeof cnt);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
