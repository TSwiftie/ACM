#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool vis[105][105];
    const int dir[4][2] = {-1,0,0,-1,1,0,0,1};
    bool dfs(const int &x,const int &y,const int &cha,const int &n,const int &m,const vector<vector<int>> &heights){
        if(x==n-1 && y== m-1) return true;
        bool ok = false;
        for(int i = 0;i < 4 && !ok; ++i){
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!vis[dx][dy] && abs(heights[dx][dy]-heights[x][y]) <= cha){
                vis[dx][dy] = true;
                ok = dfs(dx,dy,cha,n,m,heights);
            }
        }
        return ok;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        int left = 0, right = 999999, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            memset(vis,0,sizeof vis);
            if (dfs(0,0,mid,n,m,heights)) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
