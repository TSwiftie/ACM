#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int l = 0, lsum = 0, rsum = 0, ans = 0;
        for(int r = 0;r < n;++r){
            rsum += 1 - A[r];
            while(lsum < rsum - K) lsum += 1 - A[l++];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
