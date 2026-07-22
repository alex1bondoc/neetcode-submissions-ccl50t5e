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
    int maxDepth(TreeNode* root) {
        int sol{};
        stack<pair<TreeNode*, int>> st;
        if (root) {
            st.push({root, 1});
        }
        while (!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();
            sol = std::max(sol, depth);
            if (node->left) {
                st.push({node->left, depth + 1});
            }
            if (node->right) {
                st.push({node->right, depth + 1});
            }
        }
        return sol;
    }
};
