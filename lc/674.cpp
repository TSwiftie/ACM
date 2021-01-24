#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0,n = nums.size(),l = 0;
        for(int r = 0;r < n;++r){
            if(r > 0 && nums[r] <= nums[r-1]) l = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
