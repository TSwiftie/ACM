#include <bits/stdc++.h>
#include <vector>
using namespace std;
class NumMatrix {
public:
    int sum[1003][1003];
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return;
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                sum[i][j] = (i==0?0:sum[i-1][j]) + (j==0?0:sum[i][j-1]) - (i==0||j==0?0:sum[i-1][j-1]) + matrix[i][j];
        for(int i = 0;i < n;++i)
            for(int j = 0;j < m;++j)
                printf("%d%c",sum[i][j]," \n"[j==m-1]);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        --row1,--col1;
        return sum[row2][col2] - (row1<=0?0:sum[row1-1][col1]) - (col1<=0?0:sum[row1][col1-1]) + (row1<=0||col1<=0?0:sum[row1-1][col1-1]);
    }
};
