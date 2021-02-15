#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur = 0,ans = 0;
        for(int &i : nums){
            if(i==0) { ans = max(ans, cur);cur = 0; }
            else ++cur;
        }
        ans = max(ans, cur);
        return ans;
    }
};
