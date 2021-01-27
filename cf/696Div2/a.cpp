#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
char ch[100005];
signed main(void){
    int t,n;for(scanf("%d",&t);t--;){
        scanf("%d%s",&n,ch+1);
        int last = -1;
        for(int i = 1;i <= n;++i){
            if(last==-1){ putchar('1');last = 1 + (ch[i]-'0'); }
            else if(last==2){
                if(ch[i]=='1') putchar('0'),last = 1;
                else if(ch[i]=='0') putchar('1'),last = 1;
            }else if(last==1){
                if(ch[i]=='1') putchar('1'),last = 2;
                else if(ch[i]=='0') putchar('0'),last = 0;
            }else if(last==0){
                if(ch[i]=='1') putchar('1'),last = 2;
                else if(ch[i]=='0') putchar('1'),last = 1;
            }
        }
        puts("");
    }
    return 0;
}
