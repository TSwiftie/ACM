#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0,presum = 0,n = nums.size();
        for(int & i : nums) sum += i;
        for(int i = 0;i < n;++i){
            if(2*presum + nums[i] == sum) return i;
            presum += nums[i];
        }
        return -1;
    }
};
