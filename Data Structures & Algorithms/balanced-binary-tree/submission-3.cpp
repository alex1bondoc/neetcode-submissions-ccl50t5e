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
    bool isBalanced(TreeNode* root) {
        auto dfs = [](auto self, TreeNode* root) {
            if (!root) {
                return make_pair(true, 0);
            }
            auto [balancedLeft, heightLeft] = self(self, root->left);
            auto [balancedRight, heightRight] = self(self, root->right);
            bool balanced{balancedLeft && balancedRight && abs(heightLeft - heightRight) <= 1};
            int height{std::max(heightLeft, heightRight) + 1};
            return make_pair(balanced, height);
        };
        return dfs(dfs, root).first;
    }
};
