#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;
class KthLargest {
public:
    int m_k;
    multiset<int>st;
    KthLargest(int k, vector<int>& nums) {
        this->m_k = k;
        int n = nums.size();
        for(int i = 0;i < n;++i){
            if(i < k) st.insert(nums[i]);
            else{
                st.insert(nums[i]);
                st.erase(st.begin());
            }
        }
    }
    int add(int val) {
        st.insert(val);
        if(st.size() > this->m_k) st.erase(st.begin());
        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
