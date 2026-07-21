/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int sol{};
        auto func = [&sol](auto self, TreeNode* root) {
            if (!root) return make_pair(0, 0);
            auto [depthLeft, diameterLeft] = self(self, root->left);
            auto [depthRight, diameterRight] = self(self, root->right);
            sol = std::max(sol, depthLeft + depthRight);
            return make_pair(1 + std::max(depthLeft, depthRight), depthLeft + depthRight);
        };
        func(func, root);
        return sol;
    }
};