#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<TreeNode*> build(int L,int R){
        if(L > R) return {nullptr};
        vector<TreeNode*>ans;
        for(int i = L;i <= R;++i){
            vector<TreeNode*>lch = build(L, i-1);
            vector<TreeNode*>rch = build(i+1,R);
            for(auto& left : lch){
                for(auto& right : rch){
                    TreeNode* tmp = new TreeNode(i);
                    tmp->left = left;
                    tmp->right = right;
                    ans.emplace_back(tmp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return build(1, n);
    }
};
