/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月13日 星期一 14时48分25秒
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
const int N = 2e5+10;
int a[N],b[N],cnt;
signed main(void){
    int t,n;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        cnt = 0;
        b[0] = -1;
        for(int i = 1;i <= n;++i){
            scanf("%d",a+i);
            a[i] = a[i]==i;
        }
        for(int i = 1;i <= n;++i){
            if(a[i]!=b[cnt]){
                ++cnt;
                b[cnt] = a[i];
            }
        }
        int ans = 0;
        for(int i = 1;i <= cnt;++i) ans += !b[i];
        printf("%d\n",ans>2?2:ans);
    }
    return 0;
}
