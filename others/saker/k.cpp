#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 8e6+10;
int buc[N],bucc[N];
int calc(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
signed main(void){
    int n;
    scanf("%lld",&n);
    if(n==1) printf("1\n");
    else{
        int ans = 1e18;
        for(int i = 0;i < N;++i){
            int t = calc(i);
            ++buc[t];
            bucc[t] += i;
            if(buc[t] == n) ans = min(ans,bucc[t]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
