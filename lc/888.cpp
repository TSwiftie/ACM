#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = 0,sumb = 0;unordered_set<int>mp;
        vector<int>ans;
        for(const int &i : A) suma += i;
        for(const int &i : B) sumb += i;
        for(const int &i : A) mp.insert(suma - 2 * i);
        for(const int &i : B){
            if(mp.count(sumb - 2*i)){
                int a = (suma - sumb + 2 * i) >> 1;
                ans.emplace_back(a);
                ans.emplace_back(i);
                return ans;
            }
        }
        return ans;
    }
};
