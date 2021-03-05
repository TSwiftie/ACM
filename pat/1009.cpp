#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
double a[N],b[N],c[N+N],x;int n,m;
signed main(void){
    scanf("%d",&n);
    for(int i = 1,pos;i <= n;++i){
        scanf("%d%lf",&pos,&x);
        a[pos] = x;
    }
    scanf("%d",&m);
    for(int i = 1,pos;i <= m;++i){
        scanf("%d%lf",&pos,&x);
        b[pos] = x;
    }
    for(int i = 0;i <= 1000;++i){
        if(a[i]==0) continue;
        for(int j = 0;j <= 1000;++j){
            if(b[j]==0) continue;
            c[i+j] += a[i] * b[j];
        }
    }
    int cnt = 0;
    vector<pair<int,double>>ans;
    for(int i = 2001;i >= 0;--i)
        if(c[i]!=0){
            ++cnt;
            ans.push_back({i,c[i]});
        }
    printf("%d",cnt);
    for(auto &p : ans) printf(" %d %.1lf",p.first,p.second);
    return 0;
}
