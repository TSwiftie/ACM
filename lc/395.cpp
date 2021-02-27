#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0,n = s.size();
        for(int t = 1;t <= 26;++t){
            int l = 0,r = 0,tot = 0,less = 0;
            vector<int>cnt(26,0);
            while(r < n){
                ++cnt[s[r]-'a'];
                if(cnt[s[r]-'a'] == 1){ ++tot;++less; }
                if(cnt[s[r]-'a'] == k){ --less; }
                while(tot > t){
                    --cnt[s[l]-'a'];
                    if(cnt[s[l]-'a'] == k-1){ ++less; }
                    if(cnt[s[l]-'a'] == 0) { --tot;--less; }
                    ++l;
                }
                if(less==0) res = max(res, r - l + 1);
                ++r;
            }
        }
        return res;
    }
};
