/************************************************************
	> File Name: b.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: mié 08 jul 2020 11:00:48
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
const int N = 304;
int a[N][N], n, m, t;
signed main(void){
    for(scanf("%d",&t);t--;){
        bool ok = true;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;++i){
            for(int j = 1;j <= m;++j){
                scanf("%d",&a[i][j]);
                if(((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m))&&a[i][j]>2) ok = false;
                else if((i==1 || i==n) && a[i][j] > 3) ok = false;
                else if((j==1 || j==m) && a[i][j] > 3) ok = false;
                else if(a[i][j] > 4) ok = false;
            }
        }
        if(ok){
            printf("YES\n");
            for(int i = 1;i <= n;++i)
                for(int j = 1;j <= m;++j){
                    if((i==1&&j==1)||(i==1&&j==m)||(i==n&&j==1)||(i==n&&j==m)) printf("2");
                    else if((i==1 || i==n)) printf("3");
                    else if((j==1 || j==m)) printf("3");
                    else printf("4");
                    printf("%c"," \n"[j==m]);
                }
        }else printf("NO\n");
    }
    return 0;
}
