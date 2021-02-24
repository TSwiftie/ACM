#include <bits/stdc++.h>
using namespace std;
const int N = 103;
char ch[N];int sum = 0;
char dic[10][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
void print(int x){
    if(x%10 == x){
        printf("%s",dic[x]);
        return;
    }
    print(x/10);
    printf(" %s",dic[x%10]);
}
signed main(void){
    scanf("%s",ch);
    for(int i = 0,n = strlen(ch);i < n;++i)
        sum += ch[i]-'0';
    print(sum);puts("");
    return 0;
}
