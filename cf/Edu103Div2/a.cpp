#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
signed main(void){
    int t;for(scanf("%d",&t);t--;){
        ll n, k;scanf("%lld%lld",&n,&k);
        ll cnt = ceil(1.0*n/k);k *= cnt;
        ll ans = k / n + (k%n ? 1 : 0);
        printf("%lld\n",ans);
    }
    return 0;
}
