#include <bits/stdc++.h>
#include <climits>
#include <cstdio>
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
const char *mod = "puleyaknoi";
const int N = 1e5+10;
char ch[N];int g[N][30];
void solve(){
    scanf("%s",ch+1);int len = strlen(ch+1),ans = INF;
    for(int i = 0;i < 26;++i) g[len+1][i] = -1;
    for(int i = len;i;--i){
        for(int j = 0;j < 26;++j) g[i][j] = g[i+1][j];
        g[i][ch[i]-'a'] = i;
    }
    for(int i = 1;i <= len;++i){
        if(ch[i]=='p'){
            int id = 0,j = g[i][mod[id++]-'a'];
            while(j!=-1 && id < 10) j = g[j][mod[id++]-'a'];
            if(j!=-1 && id==10) ans = min(ans,j-i+1);
        }
    }
    printf("%d\n",ans==INF?-1:ans);
}
signed main(void){
    int t;for(scanf("%d",&t);t--;) solve();
    return 0;
}
