/************************************************************
	> File Name: a.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 21时04分28秒
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
int n, m;
signed main(void){
    scanf("%d%d",&n,&m);
    int Min = 1,Max = 0,ans = 0;
    for(int i = 1;i <= n;++i){
        Max = Max * 10 + 9;
        Min = Min * 10;
    }
    Min /= 10;
    for(int i = Min;i <= Max;++i){
        int tmp = i,sum = 0;
        while(tmp){
            sum += tmp%10;
            tmp /= 10;
        }
        if(sum == m){
            ans += i;
        }
    }
    printf("%d\n",ans);
    return 0;
}
