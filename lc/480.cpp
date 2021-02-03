#include <bits/stdc++.h>
#include <set>
using namespace std;
class Solution {
public:
    int gk;
    multiset<int>small,large;
    void maintain(){
        if(small.size() > large.size() + 1){
            large.insert(*small.rbegin());
            small.erase(small.find(*small.rbegin()));
        }else if(small.size() < large.size()){
            small.insert(*large.begin());
            large.erase(large.find(*large.begin()));
        }
    }
    void insert(int num){
        if(small.empty() || num <= *small.rbegin()) small.insert(num);
        else large.insert(num);
        maintain();
    }
    void erase(int num){
        if(num <= *small.rbegin()) small.erase(small.find(num));
        else large.erase(large.find(num));
        maintain();
    }
    double getMedian() { return gk & 1 ? *small.rbegin() : ((double)*small.rbegin() + *large.begin()) / 2; }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        gk = k;
        small.clear();large.clear();
        for(int i = 0;i < k;++i) insert(nums[i]);
        vector<double> ans = {getMedian()};
        for (int i = k; i < nums.size(); ++i) {
            insert(nums[i]);
            erase(nums[i - k]);
            ans.push_back(getMedian());
        }
        return ans;
    }
};
