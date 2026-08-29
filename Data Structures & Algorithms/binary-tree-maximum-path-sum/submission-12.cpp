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
#include <limits>
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sol{std::numeric_limits<int>::min()};
        unordered_map<TreeNode*, int> sum;
        auto node{root};
        TreeNode* last{};
        stack<TreeNode*> st;
        while (node || st.size()) {
            
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (!node->right || node->right == last) {
                    st.pop();
                    sol = max(sol, node->val + sum[node->left] + sum[node->right]);
                    sum[node] = std::max(max(sum[node->left], sum[node->right]), 0) + node->val;
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
