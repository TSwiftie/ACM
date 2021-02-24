#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
double a[N];
signed main(void){
    int ka, maxPos = -1,count = 0;double x;
    scanf("%d",&ka);
    for(int i = 1,pos;i <= ka;++i){
        scanf("%d %lf",&pos, &x);
        a[pos] += x;
        maxPos = max(maxPos, pos);
    }
    scanf("%d",&ka);
    for(int i = 1,pos;i <= ka;++i){
        scanf("%d %lf",&pos, &x);
        a[pos] += x;
        maxPos = max(maxPos, pos);
    }
    for(int i = 0;i < 1001;++i) if(a[i]!=0) ++count;
    printf("%d",count);
    for(int i = maxPos;i >= 0;--i)
        if(a[i]!=0)
            printf(" %d %.1lf",i, a[i]);
    puts("");
    return 0;
}
