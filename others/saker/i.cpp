#include <bits/stdc++.h>
using namespace std;
signed main(void){
    int n, x, y;
    scanf("%d%d%d",&n,&x,&y);
    int flag = 1;
    double err = 1.0 * n / 32, c = 2.0 / 3.0, ans = n * 1.0, add = n * 1.0 / 2;
    for(int i = 1; i <= y; i++){
        ans *= c;
        if(flag && i % x == 0) ans += add, flag = 0;
        if(ans < err){
            printf("N0!\n%d %.6lf\n", i, ans);
            return 0;
        }
    }
    printf("YE5!\n%.6lf\n", ans);
    return 0;
}
