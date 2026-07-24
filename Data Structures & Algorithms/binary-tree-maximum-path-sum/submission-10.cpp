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
    int maxPathSum(TreeNode* root) {
        int sol{};
        stack<TreeNode*> st;
        auto* node{root};
        TreeNode* last{};
        unordered_map<TreeNode*, int> map;
        map[nullptr] = 0;
        while (node || st.size()) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (!node->right || node->right == last) {
                    st.pop();
                    int left{map[node->left]};
                    int right{map[node->right]};
                    if (left < 0) left = 0;
                    if (right < 0) right = 0;
                    sol = max(sol, left + right + node->val);
                    map[node] = max(left, right) + node->val;
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
