/************************************************************
	> File Name: f.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月17日 星期五 11时08分56秒
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
const int N = 505;
int a[N];
signed main(void){
    int n, t;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 1;i <= n;++i) scanf("%d",a+i);
        vi ans;
        for(int i = 1;i <= n;++i){
            for(int j = 1;j < n;++j){
                if(a[j] > a[j+1]){
                    swap(a[j],a[j+2]);
                    swap(a[j],a[j+1]);
                    ans.emplace_back(j);
                    ans.emplace_back(j);
                }else if(a[j+1] > a[j+2]){
                    swap(a[j],a[j+1]);
                    swap(a[j],a[j+2]);
                    ans.emplace_back(j);
                }
            }
        }
        int i;
        for(i = 2;i <= n;++i) if(a[i] < a[i-1]) break;
        if(i <= n) printf("-1\n");
        else{
            printf("%d\n",SZ(ans));
            for(int x : ans) printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}
