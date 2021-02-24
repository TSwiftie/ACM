#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    inline void flipLine(vector<int>& line){
        int l = 0,r = line.size()-1;
        while(l < r) swap(line[l++], line[r--]);
    }
    inline void invertLine(vector<int>& line){ for(int &x : line) x = !x; }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        for(int i = 0;i < row;++i){
            flipLine(A[i]);
            invertLine(A[i]);
        }
        return A; 
    }
};
