#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum[20004];
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size(),base = 0,ans = 0;
        if(grumpy[0]) sum[0] = customers[0];
        else base = customers[0],sum[0] = 0;
        for(int i = 1;i < n;++i){
            sum[i] = sum[i-1];
            if(grumpy[i]) sum[i] += customers[i];
            else base += customers[i];
        }
        for(int i = X-1;i < n;++i) ans = max(ans, base + sum[i] - (i-X==-1 ? 0 : sum[i-X]));
        return ans;
    }
};
