/************************************************************
	> File Name: LIS.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Fri 26 Jun 2020 06:04:27 PM CST
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
mt19937 rnd(time(0));
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
const int N = 1e5+10;
int low[N],a[N];
int n, ans;
int bfind(int *a,int r,int x){
    int l = 1;
    while(l < r){
        int mid = (l+r)>>1;
        if(a[mid] >= x) r = mid;
        else l = mid+1;
    }
    return l;
}
signed main(void){
    scanf("%d",&n);
    for(int i = 1;i <= n;++i){
        scanf("%d",a+i);
        low[i] = INF;
    }
    low[1] = a[1];
    ans = 1;
    for(int i = 2;i <= n;++i){
        if(a[i] > low[ans]) low[++ans] = a[i];
        else low[bfind(low,ans,a[i])] = a[i];
    }
    printf("%d\n",ans);
    return 0;
}
