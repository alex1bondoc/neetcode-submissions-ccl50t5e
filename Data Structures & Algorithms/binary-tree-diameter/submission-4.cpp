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
        unordered_map<TreeNode*, pair<int, int>> map;
        map[nullptr] = {0, 0};
        stack<TreeNode*> st;
        if (root) st.push(root);
        while (st.size()) {
            auto* node{st.top()};
            if (node->left && !map.contains(node->left)) {
                st.push(node->left);
            }
            else if (node->right && !map.contains(node->right)) {
                st.push(node->right);
            }
            else {
                st.pop();
                auto [depthLeft, diameterLeft] = map[node->left];
                auto [depthRight, diameterRight] = map[node->right];
                int height{1 + std::max(depthLeft, depthRight)};
                int diameter{std::max(std::max(depthLeft + depthRight, diameterLeft), diameterRight)};
                map[node] = {height, diameter};
            }
        }

        return map[root].second;
    }
};