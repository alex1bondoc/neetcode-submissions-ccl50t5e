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
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> st;
        if (root)
            st.push(root);
        while (st.size()) {
            auto* tn{st.front()};
            st.pop();
            std::swap(tn->left, tn->right);
            if (tn->left) st.push(tn->left);
            if (tn->right) st.push(tn->right);
        }
        return root;
    }
};
