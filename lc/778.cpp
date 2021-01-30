#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    bool vis[55][55];
    bool bfs(const int &maxheight,const vector<vector<int>>&grid){
        int n = grid.size();queue<pair<int,int>>q;
        memset(vis,false,sizeof vis);
        if(grid[0][0] <= maxheight){ q.push({0,0});vis[0][0] = true; }
        while(q.size()){
            int x = q.front().first,y = q.front().second;q.pop();
            if(x==n-1 && y==n-1) return true;
            for(int i = 0;i < 4;++i){
                int dx = x + dir[i][0],dy = y + dir[i][1];
                if(dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
                if(!vis[dx][dy] && grid[dx][dy] <= maxheight){
                    vis[dx][dy] = true;
                    q.push({dx,dy});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0,r = n*n-1,ans = 0;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(bfs(mid, grid)){ ans = mid;r = mid-1; }
            else l = mid + 1;
        }
        return ans;
    }
};
