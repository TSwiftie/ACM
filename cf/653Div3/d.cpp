/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Mon 29 Jun 2020 08:48:33 AM CST
************************************************************/
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#include <ext/rope>
#define lowbit(x) (x&-x)
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define lc (o<<1)
#define rc (o<<1|1)
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
//mt19937 rnd(time(0));
typedef long long LL;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<LL> vll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int INF = 0x3f3f3f3f;
const LL INF_ll = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-8;
int t, n, k;
ll ans;
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d%d",&n,&k);
        ans = -1;
        map<int,int>mp;
        for(int i = 1,x;i <= n;++i){
            scanf("%d",&x);
            if(x%k) ans = max(ans,(k-x%k)+1ll*k*mp[k-(x%k)]++);
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}
