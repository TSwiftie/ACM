#include <stdio.h>
int test();
signed main(void){
    test();
    return 0;
}

int test(){
    for(int a = 0;a <= 10;++a) printf("%d\n",a);
    return 6;
}
