#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        int tot = 0,x;vector<int>ans;
        for(int i = 0;i <= num;++i){
            tot = 0;x = i;
            while(x){ tot += (x%2);x >>= 1; }
            ans.push_back(tot);
        }
        return ans;
    }
};
