#include <bits/stdc++.h>
using namespace std;
const int N = 103;
vector<int>G[N];
signed main(void){
    int n, m;scanf("%d%d",&n,&m);
    for(int i = 1,id,k,v;i <= m;++i){
        scanf("%d%d",&id,&k);
        while(k--){
            scanf("%d",&v);
            G[id].push_back(v);
        }
    }
    queue<int>q;q.push(1);
    vector<int>res;
    while(q.size()){
        int levelsize = q.size(),ans = 0;
        while(levelsize--){
            int u = q.front();q.pop();
            if(G[u].size() == 0) { ++ans;continue; }
            for(int v : G[u]) q.push(v);
        }
        res.push_back(ans);
    }
    for(int i = 0;i < res.size();++i) printf("%d%c",res[i]," \n"[i==res.size()-1]);
    return 0;
}
