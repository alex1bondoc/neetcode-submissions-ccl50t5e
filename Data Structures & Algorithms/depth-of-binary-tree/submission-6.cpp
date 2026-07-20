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
    int maxDepth(TreeNode* root) {
        std::stack<std::pair<int, TreeNode*>> st;
        int res{};
        if (root) st.push({1, root});
        while (!st.empty()) {
            auto p{st.top()};
            st.pop();
            auto depth{p.first};
            auto* node{p.second};
            if (depth > res) res = depth;
            if (node->left) st.push({depth + 1, node->left});
            if (node->right) st.push({depth + 1, node->right});

        }
        return res;
    }
};
