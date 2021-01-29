#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int dir[4][2] = {-1,0,0,-1,1,0,0,1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(),m = heights[0].size();
        int left = 0, right = 999999, ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            queue<pair<int,int>> q;
            vector<bool>vis(m*n,false);
            vis[0] = true;
            q.push({0,0});
            while(q.size()){
                int x = q.front().first,y = q.front().second;q.pop();
                if(x==n-1 && y==m-1) break;
                for(int i = 0;i < 4;++i){
                    int dx = x + dir[i][0]; 
                    int dy = y + dir[i][1];
                    int index = dx * m + dy;
                    if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
                    if(!vis[index] && abs(heights[dx][dy]-heights[x][y]) <= mid){
                        vis[index] = true;
                        q.push({dx,dy});
                    }
                }
            }
            if (vis[n * m - 1]) ans = mid,right = mid - 1;
            else left = mid + 1;
        }
        return ans;
    }
};
