#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0;i < m;++i){
            int num = matrix[0][i];
            for(int x = 0,y = i;x < n && y < m;++x,++y)
                if(matrix[x][y]!=num) return false;
        }
        for(int i = 1;i < n;++i){
            int num = matrix[i][0];
            for(int x = i,y = 0;x < n && y < m;++x,++y)
                if(matrix[x][y]!=num) return false;
        }
        return true;
    }
};
