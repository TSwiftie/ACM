#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1,n = arr.size(),dp0 = 1,dp1 = 1;
        for(int i = 1;i < n;++i){
            if(arr[i-1] > arr[i]) dp0 = dp1 + 1,dp1 = 1;
            else if(arr[i-1] < arr[i]) dp1 = dp0 + 1,dp0 = 1; 
            else dp0 = dp1 = 1;
            ans = max({ans,dp0,dp1});
        }
        return ans;
    }
};
