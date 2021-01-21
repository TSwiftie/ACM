#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dis[1004];
    inline int getdis(const int &x,const int &y,const vector<vector<int>>& points){
        return abs(points[x][0]-points[y][0])+abs(points[x][1]-points[y][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(),u,minx,ans = 0;
        for(int i = 0;i < n;++i) dis[i] = getdis(0,i,points);
        for(int k = 1;k < n;++k){
            minx = 0x3f3f3f3f;
            for(int i = 0;i < n;++i){
                if(dis[i]!=0 && dis[i] < minx){
                    u = i;
                    minx = dis[i];
                }
            }
            ans += dis[u];
            dis[u] = 0;
            for(int i = 0;i < n;++i){
                if(dis[i]!=0 && dis[i] > getdis(u,i,points)){
                    dis[i] = getdis(u,i,points);
                }
            }
        }
        return ans;
    }
};
