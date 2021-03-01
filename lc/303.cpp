#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    int sum[10005];
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;
        sum[0] = nums[0];
        int n = nums.size();
        for(int i = 1;i < n;++i) sum[i] = sum[i-1] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j] - (i==0 ? 0 : sum[i-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
