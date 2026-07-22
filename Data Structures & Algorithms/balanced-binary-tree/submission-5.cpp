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
        stack<TreeNode*> st;
        TreeNode* node = root;
        TreeNode* last = nullptr;
        unordered_map<TreeNode*, int> depth;
        while (node || !st.empty()) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (!node->right || node->right == last) {
                    st.pop();
                    int leftHeight{depth[node->left]};
                    int rightHeight{depth[node->right]};
                    if (abs(rightHeight - leftHeight) > 1) return false;
                    depth[node] = max(rightHeight, leftHeight) + 1;
                    last = node;
                    node = nullptr;
                }
                else {
                    node = node->right;
                }
            }
        }
        return true;
    }
};
