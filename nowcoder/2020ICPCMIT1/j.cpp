#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
int dif[N][N];
void add(int i,int j,int x,int y,int val){
    dif[i][j] += val;
    dif[i+x][j] -= val;
    dif[i][j+y] -= val;
    dif[i+x][j+y] += val;
}
signed main(void){
    int t;for(scanf("%d",&t);t--;){
        int n, m, a, b; scanf("%d%d%d%d",&n,&m,&a,&b);
        for(int i = 0;i <= n;++i) for(int j = 0;j <= m;++j) dif[i][j] = 0;
        for(int i = 1,x;i <= n;++i)
            for(int j = 1;j <= m;++j)
                scanf("%d",&x),add(i,j,1,1,x);
        int ok = 1;
        for(int i = 1;ok && i <= n;++i){
            for(int j = 1;ok && j <= m;++j){
                dif[i][j] = dif[i][j] + dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
                if(dif[i][j]==0) continue;
                if(dif[i][j] < 0) ok = 0;
                if(i + a - 1 <= n && j + b - 1 <= m) add(i,j,a,b,-dif[i][j]);
                else ok = 0;
            }
        }
        puts(ok ? "^_^" : "QAQ");
    }
    return 0;
}
