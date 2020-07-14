/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月14日 星期二 08时30分44秒
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
const int N = 1e3+10;
int t,n,a[N];
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            scanf("%d",a+i);
        }
        int pre,now,suf;
        bool ok = false;
        for(int i = 1;i <= n;++i){
            pre = -1,now = i, suf = -1;
            for(int j = 1;j < i;++j)
                if(a[j] < a[i]) pre = j;
            for(int j = i+1;j <= n;++j)
                if(a[j] < a[i]) suf = j;
            if(pre!=-1&&suf!=-1){
                ok = true;
                break;
            }
        }
        if(ok) printf("YES\n%d %d %d\n",pre,now,suf);
        else printf("NO\n");
    }
    return 0;
}
