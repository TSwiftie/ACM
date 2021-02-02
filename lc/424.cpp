#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cnt[30];
    int characterReplacement(string s, int k) {
        memset(cnt,0,sizeof cnt);
        int n = s.size(),maxn = 0,l = 0,r = 0;
        while(r < n){
            ++cnt[s[r]-'A'];
            maxn = max(maxn, cnt[s[r]-'A']);
            if(r - l + 1 - maxn > k) --cnt[s[l++]-'A'];
            ++r;
        }
        return r - l;
    }
};
