#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
struct record{
    char id[20];
    int hh, mm, ss;
};
bool cmp(const record &a,const record &b){
    if(a.hh == b.hh)
        if(a.mm == b.mm) return a.ss < b.ss;
        else return a.mm < b.mm;
    else return a.hh < b.hh;
}
vector<record>s;
int cnt;
signed main(void){
    int n; scanf("%d",&n);
    record tmp;
    for(int i = 0;i < n;++i){
        scanf("%s %d:%d:%d",tmp.id,&tmp.hh,&tmp.mm,&tmp.ss);
        s.push_back(tmp);
        scanf("%d:%d:%d",&tmp.hh,&tmp.mm,&tmp.ss);
        s.push_back(tmp);
    }
    sort(s.begin(),s.end(),cmp);
    printf("%s %s\n",s.begin()->id,s.rbegin()->id);
    return 0;
}
