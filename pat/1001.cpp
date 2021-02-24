#include <bits/stdc++.h>
using namespace std;
void print(int x,int cnt){
    if(!x) return;
    print(x/10,cnt+1);
    if(cnt%3==0 && x/10!=0) printf(",");
    printf("%d",x%10);
}
signed main(void){
    int a, b, sum;scanf("%d%d",&a,&b);
    sum = a + b;
    if(sum == 0){ printf("0\n");return 0; }
    if(sum < 0) printf("-"),sum = -sum;
    print(sum, 1);
    puts("");
    return 0;
}
