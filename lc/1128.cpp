#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>mp;
        int n = dominoes.size();
        int ans = 0;
        for(int i = 0;i < n;++i){
            sort(dominoes[i].begin(),dominoes[i].end());
            if(mp.count(dominoes[i])) ans += mp[dominoes[i]];
            ++mp[dominoes[i]];
        }
        return ans;
    }
};
