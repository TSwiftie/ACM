/************************************************************
	> File Name: 2678.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 10时54分44秒
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
const int N = 5e4+10;
int d[N],n,m,L;
bool check(int x){
    int last = 0,cnt = 0;
    for(int i = 1;i <= n;++i){
        if(d[i]-d[last]>=x) last = i;
        else ++cnt;
    }
    return cnt <= m;
}
signed main(void){
    scanf("%d%d%d",&L,&n,&m);
    for(int i = 1;i <= n;++i) scanf("%d",d+i);
    d[0] = 0;
    d[++n] = L;
    int l = 0,r = L,ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid)) l = mid+1,ans = mid;
        else r = mid -1;
    }
    printf("%d\n",ans);
    return 0;
}
