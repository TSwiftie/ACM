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
const int N = 5e3+10;
const int M = 1e4+10;
vi blg[M][2];
int k, n;
int sta[N],ans[N];
struct node{ int a,aa,b,bb,c,cc; }s[M];
void dfs(int u,bool flag){
    if(ans[u]==-1){
        ans[u] = flag;
        return ;
    }
}
signed main(void){
    cin >> k >> n;
    memset(ans,-1,sizeof ans);
    for(int i = 1;i <= n;++i){
        char aa, bb, cc;
        scanf("%d %c %d %c %d %c",&s[i].a,&aa,&s[i].b,&bb,&s[i].c,&cc);
        blg[s[i].a][aa!='R'].push_back(i);s[i].aa = aa=='R';
        blg[s[i].b][bb!='R'].push_back(i);s[i].bb = bb=='R';
        blg[s[i].c][cc!='R'].push_back(i);s[i].cc = cc=='R';
    }
    return 0;
}
