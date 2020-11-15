#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e7+10;
int buc[N],a[200005],n,f[N],ans;
signed main(void){
    scanf("%d",&n);for(int i = 1;i <= n;++i) scanf("%d",a+i),++buc[a[i]];
    for(int i = 2;i < N;++i){
        if(!buc[i]) continue;
        f[i] += buc[i];
        ans = max(ans,f[i]);
        for(int j = i;j < N;j+=i) f[j] = max(f[j],f[i]);
    }
    printf("%d\n",ans+buc[1]);
    return 0;
}
