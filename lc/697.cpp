#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int>buc[50000];
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size(), MaxSize = 0, MaxNum = -1;
        for(int i = 0;i < n;++i){
            buc[nums[i]].push_back(i);
            MaxNum = max(MaxNum, nums[i]);
            MaxSize = max(MaxSize, (int)buc[nums[i]].size());
        }
        int ans = 50000;
        for(int i = 0;i <= MaxNum;++i)
            if(buc[i].size() == MaxSize)
                ans = min(ans, *buc[i].rbegin() - *buc[i].begin() + 1);
        return ans;
    }
};
