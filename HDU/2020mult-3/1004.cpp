/************************************************************
	> File Name: 1004.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Tue 28 Jul 2020 12:37:42 PM CST
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
const int N = 1e5+10;
int T, n, p, a[N], sum[N], last[N], ans;
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&p);
        sum[0] = ans = 0;
        for(int i = 1;i <= n;++i) scanf("%d",a+i),a[i] %= p,sum[i] = sum[i-1] + a[i];
        memset(last,-1,sizeof last);
        last[0] = 0;
        int pos = 0;
        for(int i = 1;i <= n;++i){
            int tmp = last[sum[i]%p];
            if(tmp >= pos){
                ++ans;
                pos = i;
            }
            last[sum[i]%p] = i;
        }
        printf("%d\n",ans);
    }
    return 0;
}
