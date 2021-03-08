#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int>f(n,0x3f3f3f3f);
        vector<vector<int>>check(n, vector<int>(n,false));
        for(int len = 0;len < n;++len){
            for(int st = 0;st + len < n;++st){
                int ed = st + len;
                if(len == 0) check[st][ed] = true;
                else if(len == 1) check[st][ed] = (s[st] == s[ed]);
                else check[st][ed] = (s[st]==s[ed] && check[st + 1][ed - 1]);
            }
        }
        for(int i = 0;i < n;++i){
            if(check[0][i])
                f[i] = 0;
            else
                for(int j = 0;j < i;++j)
                    if(check[j+1][i]) f[i] = min(f[j] + 1,f[i]);
        }
        return f[n-1];
    }
};
