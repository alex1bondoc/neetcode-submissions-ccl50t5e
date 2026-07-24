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
        int min{numeric_limits<int>::min()};
        int max{numeric_limits<int>::max()};
        st.push({root, min, max});

        while (st.size()) {
            auto [node, mini, maxi]{st.top()};
            st.pop();
            if (!node) continue;
            if (node->val <= mini || node->val >= maxi) return false;
            st.push({node->left, mini, node->val});
            st.push({node->right, node->val, maxi});
        }
        return true;
    }
};
