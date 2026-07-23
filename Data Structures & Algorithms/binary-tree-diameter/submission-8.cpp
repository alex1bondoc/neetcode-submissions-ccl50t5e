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
    int diameterOfBinaryTree(TreeNode* root) {
        int sol{};
        unordered_map<TreeNode*, int> depths;
        stack<TreeNode*> st;
        depths[nullptr] = 0;
        auto* node{root};
        TreeNode* last{};
        while (node || st.size()) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (!node->right || node->right == last) {
                    st.pop();
                    int left{depths[node->left]};
                    int right{depths[node->right]};
                    sol = max(sol, left + right);
                    depths[node] = max(left, right) + 1;
                    last = node;
                    node = nullptr;
                }
                else {
                    node = node->right;
                }
            }
        }
        return sol;
    }
};