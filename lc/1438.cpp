#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> qMax,qMin;
        int n = nums.size(),l = 0,ans = 0;
        for(int r = 0;r < n;++r){
            while(!qMax.empty() && qMax.back() < nums[r]) qMax.pop_back();
            while(!qMin.empty() && qMin.back() > nums[r]) qMin.pop_back();
            qMax.push_back(nums[r]);qMin.push_back(nums[r]);
            while(!qMax.empty() && !qMin.empty() && qMax.front() - qMin.front() > limit){
                if(nums[l] == qMin.front()) qMin.pop_front();
                if(nums[l] == qMax.front()) qMax.pop_front();
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
