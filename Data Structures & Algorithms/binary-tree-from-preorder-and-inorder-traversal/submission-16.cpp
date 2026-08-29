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
        unordered_map<int, int> poz;
        for (int i{}; i < n; ++i) {
            poz[inorder[i]] = i;
        }
        int k{};
        auto dfs = [&](auto self, int l, int r) -> TreeNode*{
            if (l > r) return nullptr;
            auto head{new TreeNode{preorder[k ++]}};
            head->left = self(self, l, poz[head->val] - 1);
            head->right = self(self, poz[head->val] + 1, r);
            return head;
        };
        return dfs(dfs, 0, n - 1);
    }
};
