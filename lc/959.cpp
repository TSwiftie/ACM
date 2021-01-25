#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f[4 * 30 * 30 + 10],blocks;
    int find(const int &x){ return f[x] == x ? x : f[x] = find(f[x]); }
    void Union(const int &x,const int &y){
        int fx = find(x),fy = find(y);
        if(fx != fy){
            f[fy] = fx;
            --blocks;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        blocks = 4 * n * n;
        for(int i = 0;i <= blocks;++i) f[i] = i;
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                int index = 4 * (i * n + j);
                char c = grid[i][j];
                if(c == '/'){
                    Union(index, index + 3);
                    Union(index + 1, index + 2);
                }else if(c == '\\'){
                    Union(index, index + 1);
                    Union(index + 2, index + 3);
                }else{
                    Union(index, index + 1);
                    Union(index + 1, index + 2);
                    Union(index + 2, index + 3);
                }
                if(j + 1 < n) Union(index + 1, 4 * (i * n + j + 1) + 3);
                if(i + 1 < n) Union(index + 2, 4 * ((i + 1) * n + j));
            }
        }
        return blocks;
    }
};
