#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f[100005],blocks,base[100005],baseblocks;
    int find(const int &x){ return f[x] == x ? x : f[x] = find(f[x]); }
    inline void init(const int &N){ blocks = N;for(int i = 0;i <= N;++i) f[i] = i; }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        init(n);int ans = 0;
        for(const vector<int> &edge : edges){
            if(edge[0]!=3) continue;
            int fx = find(edge[1]),fy = find(edge[2]);
            if(fx!=fy){ f[fy] = fx;--blocks; }
            else ++ans;
        }
        if(blocks==1) return (edges.size() - n + 1);
        for(int i = 0;i <= n;++i) base[i] = f[i];
        baseblocks = blocks;
        for(const vector<int> &edge : edges){
            if(edge[0]!=1) continue;
            int fx = find(edge[1]),fy = find(edge[2]);
            if(fx!=fy){ f[fy] = fx;--blocks; }
            else ++ans;
        }
        if(blocks!=1) return -1;
        for(int i = 0;i <= n;++i) f[i] = base[i];
        blocks = baseblocks;
        for(const vector<int> &edge : edges){
            if(edge[0]!=2) continue;
            int fx = find(edge[1]),fy = find(edge[2]);
            if(fx!=fy){ f[fy] = fx;--blocks; }
            else ++ans;
        }
        if(blocks!=1) return -1;
        return ans;
    }
};
