#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        bool ok1 = true,ok2 = true;
        for(int i = 1;i < n;++i){
            if(A[i] >= A[i-1]) continue;
            ok1 = false;
            break;
        }
        for(int i = 1;i < n;++i){
            if(A[i] <= A[i-1]) continue;
            ok2 = false;
            break;
        }
        return ok1 || ok2;
    }
};
