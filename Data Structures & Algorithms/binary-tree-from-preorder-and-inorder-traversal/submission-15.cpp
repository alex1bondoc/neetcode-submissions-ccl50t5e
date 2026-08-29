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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n{static_cast<int>(preorder.size())};
        int pred{};
        int in{};
        auto build = [&](auto self, int limit) -> TreeNode* {
            if (pred >= n) return nullptr;
            if (inorder[in] == limit) {
                in ++;
                return nullptr;
            }
            auto head{new TreeNode(preorder[pred++])};
            head->left = self(self, head->val);
            head->right = self(self, limit);
            return head;
        };
        return build(build, 1 << 30);
    }
};
