/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月17日 星期五 11时57分58秒
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
const int N = 103;
char ch[N];
signed main(void){
    int t;
    for(scanf("%d",&t);t--;){
        scanf("%s",ch+1);
        int len = strlen(ch+1),ze = 0,on = 0;
        for(int i = 1;i <= len;++i){
            if(ch[i]=='0') ++ze;
            else ++on;
        }
        int ans = min(on,ze);
        if(ans&1) printf("DA\n");
        else printf("NET\n");
    }
    return 0;
}
