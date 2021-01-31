#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f[103],blocks;
    int find(const int &x){ return f[x] == x ? x : f[x] = find(f[x]); }
    bool judge(const string &a,const string &b){
        int n = a.size(),cnt = 0;
        for(int i = 0;i < n;++i)
            if(a[i] != b[i])
                if(++cnt > 2)
                    return false;
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        blocks = n;
        for(int i = 0;i < blocks;++i) f[i] = i;
        for(int i = 0;i < n-1;++i){
            for(int j = i + 1;j < n;++j){
                if(judge(strs[i], strs[j])){
                    int fx = find(i),fy = find(j);
                    if(fx != fy) f[fy] = fx,--blocks;
                }
            }
        }
        return blocks;
    }
};
