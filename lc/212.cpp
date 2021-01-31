#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int dir[4][2] = {1,0,0,1,-1,0,0,-1};
    bool vis[15][15],res;
    bool dfs(const string &word, const int &pos, const int &x, const int &y, const int &n,const int &m,const vector<vector<char>>&board){
        if(pos+1 == word.size()) return true;
        bool res = false;
        for(int i = 0;i < 4 && !res;++i){
            int dx = x + dir[i][0],dy = y + dir[i][1];
            if(dx < 0 || dx >= n || dy < 0 || dy >= m) continue;
            if(!vis[dx][dy] && word[pos+1] == board[dx][dy]){
                vis[dx][dy] = true;
                res = dfs(word, pos+1, dx, dy, n, m, board);
                vis[dx][dy] = false;
            }
        }
        return res;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        int n = board.size(),m = board[0].size();
        for(const string & word : words){
            bool res = false;
            for(int i = 0;i < n && !res;++i){
                for(int j = 0;j <m && !res;++j){
                    if(word[0] == board[i][j]){
                        memset(vis,0,sizeof vis);
                        vis[i][j] = true;
                        res = dfs(word, 0, i, j, n, m, board);
                    }
                }
            }
            if(res) ans.emplace_back(word);
        }
        return ans;
    }
};
