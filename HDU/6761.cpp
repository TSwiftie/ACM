/************************************************************
	> File Name: 6761.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 22 Jul 2020 02:27:15 PM CST
************************************************************/
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
const int N = 1e6+10;
const int p = 1e9+7;
char ch[N];
int ans[N],tn[N];
void solve(){
    scanf("%s",ch+1);
    int n = strlen(ch+1);
    int cnt = 0;
    int i = 1;
    while(i <= n){
        int j = i+1,k = i;
        ans[i] = i;
        while(j <= n && ch[k] <= ch[j]){
            if(k==i) ans[j-1] = i;
            else ans[j-1] = ans[k-1] + (j-k);
            if(ch[k]==ch[j]) ++k;
            else k = i;
            ++j;
        }
        while(i <= k){
            i += j-k;
            tn[++cnt] = i-1;
        }
    }
    for(int i = 1;i <= cnt;++i) ans[tn[i]] = tn[i-1] + 1;
    int res = 0,tmp = 1;
    for(int i = 1;i <= n;++i){
        res = (res + tmp * ans[i] % p) % p;
        tmp = tmp * 1112 % p;
    }
    printf("%lld\n",res);
}
signed main(void){
    int T;
    for(scanf("%lld",&T);T--;) solve();
    return 0;
}
