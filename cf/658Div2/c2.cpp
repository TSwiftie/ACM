/************************************************************
	> File Name: c2.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Wed 22 Jul 2020 07:03:59 PM CST
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
char a[N],b[N];
vi ans;
signed main(void){
    int t, n;
    for(scanf("%d",&t);t--;ans.clear()){
        scanf("%d",&n);
        scanf("%s",a);
        scanf("%s",b);
        for(int i = 0;i < n;++i){
            int j = i / 2;
            if(i&1) j = n - 1 - j;
            if(abs(a[j] - b[n-1-i])!=((i+1)&1)) ans.push_back(1);
            ans.push_back(n-i);
        }
        printf("%d ",SZ(ans));
        for(int i : ans) printf("%d ",i);
        printf("\n");
    }
    return 0;
}
