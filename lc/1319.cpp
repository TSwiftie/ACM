#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f[100005];
    int find(const int &x){
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        for(int i = 0;i < n;++i) f[i] = i;
        int more = 0,blocks = n;
        for(vector<int> & i : connections){
            int u = i[0],v = i[1];
            int fu = find(u),fv = find(v);
            if(fu!=fv){
                --blocks;
                f[fv] = fu;
            }else ++more;
        }
        return more >= blocks-1 ? blocks-1 : -1;
    }
};
