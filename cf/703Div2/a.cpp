#include <bits/stdc++.h>
using namespace std;
signed main(void){
    int t;for(scanf("%d",&t);t--;){
        int n;long long sum = 0,asum = 0;
        scanf("%d",&n);
        for(int i = 0,x;i < n;++i){
            scanf("%d",&x);
            sum += x;asum += i;
        }
        puts(sum < asum ? "NO" : "YES");
    }
    return 0;
}
