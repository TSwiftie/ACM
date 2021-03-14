#include <bits/stdc++.h>
using namespace std;
const char ch[] = "ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd";
signed main(void){
    int len = strlen(ch);
    for(int i = 0;i < len;++i){
        if(ch[i]=='i' || ch[i]=='l' || ch[i]=='n' || ch[i]=='k' || ch[i]=='e'){
            printf("%c",ch[i]);
            i += 3;
            continue;
        }else{
            printf("%c",ch[i]);
        }
    }
    return 0;
}
