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
const int N = 9*1e5+4;
char s[N],str[N];int p[N];
int init(){
    int len = strlen(s);
    str[0] = '@',str[1] = '#';
    int j = 2;
    for(int i = 0;i < len;++i) str[j++] = s[i],str[j++] = '#';
    str[j] = '\0';
    return j;
}
int manacher(){
    int len = init(),sum = -1;
    int mx = 0,id = 0,ans = -1;
    for(int i = 1;i < len;++i){
        if(i < mx) p[i] = min(p[id*2-i],mx-i);
        else p[i] = 1;
        while(str[i+p[i]] == str[i-p[i]]) ++p[i];
        if(p[i] + i > mx) mx = p[i] + i,id = i;
        ans = max(ans,p[i]-1);
        if(mx == len) sum = max(sum,ans);
        ans = 0;
    }
    return sum;
}
signed main(void){
    int t;cin >> t;for(int i = 0;i < t;++i) cin >> s[i];
    if(manacher()==0) cout << t-1 << endl;
    else cout << t-manacher() << endl;
    return 0;
}
