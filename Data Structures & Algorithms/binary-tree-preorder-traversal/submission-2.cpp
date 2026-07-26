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
    vector<int> preorderTraversal(TreeNode* root) {
        auto node{root};
        vector<int> res{};
        while (node) {
            if (!node->left) {
                res.push_back(node->val);
                node = node->right;
            }
            else {
                auto pred{node->left};
                while (pred->right && pred->right != node) {
                    pred = pred->right;
                }
                if (!pred->right) {
                    pred->right = node;
                    res.push_back(node->val);
                    node = node->left;
                }
                else {
                    pred->right = nullptr;
                    node = node->right;
                }
            }
        }
        return res;
    }
};