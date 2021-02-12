#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tri[35][35];
    Solution(){
        tri[0][0] = 1;
        tri[1][0] = tri[1][1] = 1;
        for(int i = 2;i <= 33;++i){
            tri[i][0] = tri[i][i] = 1;
            for(int j = 1;j < i;++j)
                tri[i][j] = tri[i-1][j-1] + tri[i-1][j];
        }
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int i = 0;i <= rowIndex;++i) ans.emplace_back(tri[rowIndex][i]);
        return ans;
    }
};
