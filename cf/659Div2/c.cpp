/************************************************************
	> File Name: c.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 26 Jul 2020 10:24:48 AM CST
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
int T,n,to[30][30],ans;char A[N],B[N];
signed main(void){
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        scanf("%s%s",A+1,B+1);
        memset(to,0,sizeof to);
        bool ok = true;
        for(int i = 1;i <= n;++i){
            if(A[i] > B[i]){
                ok = false;
                break;
            }
            ++to[A[i]-'a'][B[i]-'a'];
        }
        if(!ok){
            printf("-1\n");
            continue;
        }
        ans = 0;
        for(int i = 0;i < 20;++i){
            for(int j = i+1;j < 20;++j)
                if(to[i][j]){
                    ++ans;
                    for(int k = j;k < 20;++k) to[j][k] += to[i][k];
                    break;
                }
        }
        printf("%d\n",ans);
    }
    return 0;
}
