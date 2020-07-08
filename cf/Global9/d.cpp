/************************************************************
	> File Name: d.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: mié 08 jul 2020 21:17:10
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
int t,n,a[N],c[N],x[5*N];
signed main(void){
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 0;i < n;++i){
            scanf("%d",a+i);
            ++c[a[i]];
        }
        int s = 0,i,j;
        while(true){
            for(i = 1;i < n && a[i]>=a[i-1];++i);
            if(i >= n) break;
            for(i = 0;c[i];++i);
            x[s++] = j = i-(i>=n);
            n -= i>=n;
            c[a[j]]--,c[i]++,a[j] = i;
        }
        printf("%d\n",s);
        for(i = 0;i < s;++i) printf("%d ",x[i]+1);
        puts("");
        memset(c,0,sizeof c);
    }
    return 0;
}
