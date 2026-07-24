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
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> st;
        int res{};
        st.push({root, 1 << 31});
        while (st.size()) {
            auto [node, maxi] = st.top();
            st.pop();
            if (!node) {
                continue;
            }
            if (node->val >= maxi) res++;
            st.push({node->right, max(maxi, node->val)});
            st.push({node->left, max(maxi, node->val)});
        }
        return res;
    }
};
