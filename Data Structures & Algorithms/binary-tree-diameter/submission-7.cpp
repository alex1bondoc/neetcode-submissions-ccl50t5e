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
        unordered_map<TreeNode*, int> map; // [node] => (height, maxDiameter)
        stack<TreeNode*> st; // for DFS
        int sol{};
        map[nullptr] = 0;
        TreeNode* last{nullptr};
        auto* node{root};
        while (node || !st.empty()) {
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
                    sol = max(sol, left + right);
                    map[node] = max(left, right) + 1;
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