#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;++i){
            int x = (nums[i]-1)%n;
            nums[x] += n;
        }
        vector<int>ans;
        for(int i = 1;i <= n;++i){
            if(nums[i-1] <= n)
                ans.emplace_back(i);
        }
        return ans;
    }
};
