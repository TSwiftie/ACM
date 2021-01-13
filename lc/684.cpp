#include <bits/stdc++.h>
#include <utility>
using namespace std;
class Solution {
public:
    int find(int x,vector<int>f){
        return f[x]==x ? x : f[x]=find(f[x],f);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>f(1003);int cnt = 0;
        for(int i = 1;i < 1003;++i) f[i] = i;
        for(auto &edge : edges){
            int u = edge[0],v = edge[1];
            int fu = find(u,f),fv = find(v,f);
            if(fu!=fv){
                f[fv] = fu;
                ++cnt;
            }else return vector<int>{u,v};
        }
        return vector<int>();
    }
};
