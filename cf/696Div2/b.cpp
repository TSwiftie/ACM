#include <bits/stdc++.h>
using namespace std;
bool vis[20160];
signed main(void){
    for(int i = 2;i < 144;++i)
        if(!vis[i])
            for(int j = i * i;j < 20160;j += i)
                vis[j] = true;
    int t;for(scanf("%d",&t);t--;){
        int d,x,y;scanf("%d",&d);
        for(x = d + 1;vis[x];) ++x;
        for(y = x + d;vis[y];) ++y;
        printf("%d\n",x*y);
    }
    return 0;
}
