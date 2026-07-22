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
        TreeNode* node{root};
        TreeNode* last{nullptr};
        unordered_map<TreeNode*, int> depths;
        while (st.size() || node) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (!node->right || last == node->right) {
                    st.pop();
                    int left{depths[node->left]};
                    int right{depths[node->right]};
                    if (abs(left - right) > 1) return false;
                    depths[node] = max(left, right) + 1;
                    last = node;
                    node = nullptr;
                }
                else node = node->right;
            }
        }
        return true;
    }
};
