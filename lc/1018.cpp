#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int last = 0;
        vector<bool>ans;
        for(int i = 0,len = A.size();i < len;++i){
            last = (last << 1) % 5;
            last = (last + A[i]) % 5;
            ans.emplace_back(last?0:1);
        }
        return ans;
    }
};
