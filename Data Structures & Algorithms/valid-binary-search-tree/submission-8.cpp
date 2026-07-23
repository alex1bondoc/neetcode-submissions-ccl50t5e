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
    bool isValidBST(TreeNode* root) {
        stack<tuple<TreeNode*, int, int>> st;
        st.push({root, 1 << 31, 1 << 30});
        while (st.size()) {
            auto [node, min, max] = st.top();
            st.pop();
            if (!node) continue;
            if (node->val <= min || node->val >= max) return false;
            if (node->left) st.push({node->left, min, node->val});
            if (node->right) st.push({node->right, node->val, max});
        }
        return true;
    }
};
