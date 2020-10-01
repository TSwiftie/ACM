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
const char *INPUT = "/home/ts/code/in.in";
const int p = 1e9+7;
const int N = 105;
struct Mat{
    int mat[N][N],n;
    Mat(int _n): n(_n) { memset(mat,0,sizeof mat); }
    Mat operator * (const Mat &b) const{
        Mat res = Mat(n);
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                for(int k = 0;k < n;++k)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * b.mat[k][j]) % p;
        return res;
    }
};
Mat Mat_ksm(Mat a,int b){
    Mat res = Mat(a.n);
    for(int i = 0;i < a.n;++i) res.mat[i][i] = 1;
    for(;b;b >>= 1,a = a * a) if(b&1) res = res * a;
    return res;
}
struct AC{
    static const int maxn = 195;
    int nxt[maxn][26],fail[maxn],tot = 0;bool vis[maxn];
    inline void insert(int len,char *s){
        int rt = 0;
        for(int i = 0;i < len;++i){
            if(!nxt[rt][s[i]-'a']) nxt[rt][s[i]-'a'] = ++tot;
            rt = nxt[rt][s[i]-'a'];
        }
        vis[rt] = 1;
    }
    inline void build(){
        queue<int>q;
        for(int i = 0;i < 26;++i) if(nxt[0][i]) q.push(nxt[0][i]);
        while(q.size()){
            int u = q.front();q.pop();
            for(int i = 0;i < 26;++i){
                if(nxt[u][i]){
                    fail[nxt[u][i]] = nxt[fail[u]][i];
                    vis[nxt[u][i]] |= vis[nxt[fail[u]][i]];
                    q.push(nxt[u][i]);
                }else nxt[u][i] = nxt[fail[u]][i];
            }
        }
    }
    inline Mat init(){
        Mat res = Mat(tot+2);
        for(int i = 0;i <= tot;++i)
            for(int j = 0;j < 26;++j)
                if(!vis[nxt[i][j]]) ++res.mat[i][nxt[i][j]];
        for(int i = 0;i <= tot+1;++i) res.mat[i][tot+1] = 1;
        return res;
    }
}ac;
int n, L;char str[N];
inline void solve(){
    cin >> L >> n;for(int i = 0,x;i < n;++i) cin >> x >> str,ac.insert(x, str);
    ac.build();
    Mat a = ac.init();a = Mat_ksm(a, L);
    int ans = 0;
    for(int i = 0;i < a.n-1;++i) ans = (ans + a.mat[0][i]) % p;
    cout << ans << endl;
}
signed main(void){
    IOS;solve();
    return 0;
}
