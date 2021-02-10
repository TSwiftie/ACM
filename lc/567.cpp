#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int buc[26];
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        if(n > m) return false;
        memset(buc, 0, sizeof buc);
        for(int i = 0;i < n;++i) --buc[s1[i]-'a'];
        int l = 0;
        for(int r = 0;r < m;++r){
            int x = s2[r] - 'a';
            ++buc[x];
            while(buc[x] > 0) --buc[s2[l++]-'a'];
            if(r - l + 1 == n) return true;
        }
        return false;
    }
};
