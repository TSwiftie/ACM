#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diff[30000+10];
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        memset(diff,0,sizeof diff);
        int ans = 0,revCnt = 0;
        for(int i = 0;i < n;++i){
            revCnt ^= diff[i];
            if(A[i] == revCnt){
                if(i + K  > n) return -1;
                ++ans;
                revCnt ^= 1;
                diff[i + K] ^= 1;
            }
        }
        return ans;
    }
};
