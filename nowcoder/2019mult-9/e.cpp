/************************************************************
	> File Name: e.cpp
	> Author: TSwiftie
	> Mail: tswiftie@foxmail.com 
	> Created Time: Sun 19 Jul 2020 08:50:01 PM CST
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
const int N = 1e5+10;
int f[N],sz[N];
ull n,m;
ull C[N][5];
int find(int x){
    return x==f[x]?x:f[x]=find(f[x]);
}
void init(){
    for(int i = 1;i <= n;++i) f[i] = i,sz[i] = 1;
    C[1][0] = 1;C[1][1] = 1;
    C[2][0] = 1;C[2][1] = 2;C[2][2] = 1;
    C[3][0] = 1;C[3][1] = 3;C[3][2] = 3;C[3][3] = 1;
    for(int i = 4;i < N;++i){
        C[i][0] = 1;
        for(int j = 1;j <= 4;++j)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
}
signed main(void){
    scanf("%llu%llu",&n,&m);
    init();
    ull sum = n*(n-1)/2*(n-2)/3*(n-3)/4,k = 0;
    while(m--){
        printf("%llu\n",sum);
        int u, v;
        scanf("%d%d",&u,&v);
        int x = find(u),y = find(v);
        if(x!=y){
            ll rem = n - sz[x] - sz[y];
            k -= C[sz[x]][2];
            k -= C[sz[y]][2];
            ll res = C[rem][2] - k;
            sum -= 1ll*res*sz[x]*sz[y];
            sz[x] += sz[y];
            f[y] = x;
            k += C[sz[x]][2];
        }
    }
    printf("%llu\n",sum);
    return 0;
}
