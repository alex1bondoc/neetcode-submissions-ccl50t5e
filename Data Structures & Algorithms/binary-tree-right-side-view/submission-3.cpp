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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> sol{};
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int size{static_cast<int>(q.size())};
            for (int i{}; i < size; ++i) {
                auto* node{q.front()};
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right)q.push(node->right);
                if (i == size - 1) {
                    sol.push_back(node->val);
                }
            }
        }

        return sol;
    }
};
