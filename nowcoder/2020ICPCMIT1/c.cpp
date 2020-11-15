#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char ch[100005];int cnt,ans;
signed main(void){
    scanf("%s",ch+1);int n = strlen(ch+1);
    for(int i = 1;i <= n;++i){
        if(ch[i]=='w') ++cnt;
        else ans += max(0,2*cnt-1),cnt = 0;
    }
    if(cnt != 0) ans += (2*cnt-1);
    printf("%d\n",ans);
    return 0;
}
