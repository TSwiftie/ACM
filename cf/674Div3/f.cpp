#include <bits/stdc++.h>
#include <cctype>
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
const int N = 2e5+10;
const int mod = 1e9+7;
int pre[4][N],suf[4][N],n;char ch[N];
signed main(void){
    scanf("%d%s",&n,ch+1);
    for(int i = 1;i <= n;++i){
        for(int j = 0;j < 4;++j) pre[j][i] = pre[j][i-1];
        if(ch[i]>='a' && ch[i]<='c') ++pre[ch[i]-'a'][i];
        else ++pre[3][i];
    }
    for(int i = n;i >= 1;--i){
        for(int j = 0;j < 4;++j) suf[j][i] = suf[j][i+1];
        if(ch[i]>='a' && ch[i]<='c') ++suf[ch[i]-'a'][i];
        else ++suf[3][i];
    }
    return 0;
}
/*
 *
 * ac?b?c
 * 9 + 
 *
 *
 * */
