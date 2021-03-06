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
    void Swap(TreeNode* rt){
        if(rt==nullptr) return;
        Swap(rt->left);Swap(rt->right);
        TreeNode *tmp = rt->left;
        rt->left = rt->right;
        rt->right = tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        Swap(root);
        return root;
    }
};
