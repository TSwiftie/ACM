#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0,n = nums.size();
        for(int i = 0;i < n;i += 2) ans += nums[i];
        return ans;
    }
};
