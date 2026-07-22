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
        unordered_map<TreeNode*, pair<int, int>> map; // [node] => (height, maxDiameter)
        stack<TreeNode*> st; // for DFS
        if (root) {
            st.push(root);
        }
        map[nullptr] = {0, 0};
        while (!st.empty()) {
            auto* node{st.top()};
            if (node->left && !map.contains(node->left)) {
                st.push(node->left);
            }
            else if (node->right && !map.contains(node->right)) {
                st.push(node->right);
            }
            else {
                st.pop();
                auto [leftHeight, leftDiameter] = map[node->left];
                auto [rightHeight, rightDiameter] = map[node->right];
                int height{max(leftHeight, rightHeight) + 1};
                int diameter{max(leftDiameter, max(rightDiameter, leftHeight + rightHeight))};
                // int diameter{max({leftDiameter, rightDiameter, leftHeight + rightHeight})}
                map[node] = {height, diameter};
            }

        }
        return map[root].second;
    }
};