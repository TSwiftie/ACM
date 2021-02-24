#include <bits/stdc++.h>
using namespace std;
signed main(void){
    int n, x;scanf("%d",&n);
    vector<int>v(n);
    int l = 0,r = n-1,sum = -1,tmp = 0,tmpindex = 0;
    for(int i = 0;i < n;++i){
        scanf("%d",&v[i]);
        tmp += v[i];
        if(tmp < 0){
            tmp = 0;
            tmpindex = i + 1;
        }else if(tmp > sum){
            sum = tmp;
            l = tmpindex;
            r = i;
        }
    }
    if(sum < 0) sum = 0;
    printf("%d %d %d\n",sum, v[l], v[r]);
    return 0;
}
