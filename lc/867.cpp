#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>ans;
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i < m;++i){
            vector<int>line;
            for(int j = 0;j < n;++j) line.push_back(matrix[j][i]);
            ans.push_back(line);
        }
        return ans;
    }
};