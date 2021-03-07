#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(),maxlen = 0;
        string ans;
        vector<vector<int>>f(n, vector<int>(n));
        for(int len = 0;len < n;++len){
            for(int st = 0;st + len < n;++st){
                int ed = st + len;
                if(len == 0) f[st][ed] = true;
                else if(len == 1) f[st][ed] = s[st] == s[ed];
                else f[st][ed] = (s[st] == s[ed]) && f[st+1][ed-1];
                if(f[st][ed] && len + 1 > ans.size()) ans = s.substr(st, len+1);
            }
        }
        return ans;
    }
};
