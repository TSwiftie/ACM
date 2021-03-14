#include <bits/stdc++.h>
using namespace std;
signed main(void){
    int A,B,a,b;scanf("%d%d%d%d",&A,&B,&a,&b);
    printf("%d\n",(int)ceil(ceil(A/a)/2) * (int)ceil(ceil(B/b)/2));
    return 0;
}
