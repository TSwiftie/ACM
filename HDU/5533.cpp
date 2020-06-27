/************************************************************
	> File Name: 5533.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sat 27 Jun 2020 11:35:53 AM CST
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
const int N = 1003;
int x[N],y[N];
int dis[N];
double Dis(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
signed main(void){
    int t,n;
    for(scanf("%d",&t);t--;){
        scanf("%d",&n);
        for(int i = 0;i < n;++i) scanf("%d%d",x+i,y+i);
        if(n!=4) printf("NO\n");
        else{
            int k = 0;
            for(int i = 0;i < n;++i)
                for(int j = 0;j < i;++j)
                    dis[k++] = Dis(x[i],y[i],x[j],y[j]);
            sort(dis,dis+6);
            if(dis[0]==dis[1]&&dis[1]==dis[2]&&dis[2]==dis[3]&&dis[4]==dis[5]&&dis[4]!=dis[0])
                printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
