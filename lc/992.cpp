#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int buc[20005];
    int atMostKDistinct(const vector<int>&A, const int &K){
        int n = A.size();
        memset(buc,0,sizeof buc);
        int l = 0,r = 0,uni = 0,res = 0;
        while(r < n){
            if(buc[A[r]] == 0) ++uni;
            ++buc[A[r++]];
            while(uni > K){
                --buc[A[l]];
                if(buc[A[l]] == 0) --uni;
                ++l;
            }
            res += r-l;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostKDistinct(A, K) - atMostKDistinct(A, K-1);
    }
};
