/************************************************************
	> File Name: h.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: 2020年07月16日 星期四 16时54分09秒
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
const int N = 10;
vi G[N];
int t,di[N],du[N];
signed main(void){
    for(scanf("%d",&t);t--;){
        for(int i = 1,a,b;i < 6;++i){
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
            ++di[a];
            ++di[b];
        }
        for(int i = 1;i <= 6;++i) ++du[di[i]];
        if(du[3]==2) printf("2,3-dimethylbutane\n");
        else if(du[4]==1) printf("2,2-dimethylbutane\n");
        else if(du[3]==0) printf("n-hexane\n");
        else{
            bool mark = false;
            for(int i = 1;i <= 6;++i){
                if(mark) break;
                if(di[i]==1){
                    for(int v : G[i]){
                        if(mark) break;
                        for(int s : G[v]) if(s!=i){
                            if(di[s]==1){
                                mark = true;
                                break;
                            }
                        }
                    }
                }
            }
            if(mark) printf("2-methylpentane\n");
            else printf("3-methylpentane\n");
        }
        memset(du,0,sizeof du);
        memset(di,0,sizeof di);
        for(int i = 0;i < N;++i) G[i].clear();
    }
    return 0;
}
