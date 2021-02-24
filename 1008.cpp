#include <bits/stdc++.h>
using namespace std;
const int N = 105;
signed main(void){
    int n,pre = 0,ans = 0;scanf("%d",&n);
    for(int i = 1,x;i <= n;++i){
        scanf("%d",&x);
        if(x-pre < 0) ans += 4*(pre-x);
        else ans += 6*(x-pre);
        ans += 5;
        pre = x;
    }
    printf("%d\n",ans);
    return 0;
}
//2 * 6 + 5 + 6 + 5  + 2 * 4;
