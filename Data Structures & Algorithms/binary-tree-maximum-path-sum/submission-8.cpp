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
    int res{};
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (left < 0) {
            left = 0;
        }
        if (right < 0) {
            right = 0;
        }
        res = std::max(res, right + left + node->val);
        return std::max(node->val + right, node->val + right);
    }
    int maxPathSum(TreeNode* root) {
        res = root->val;
        dfs(root);
        return res;
    }
};
