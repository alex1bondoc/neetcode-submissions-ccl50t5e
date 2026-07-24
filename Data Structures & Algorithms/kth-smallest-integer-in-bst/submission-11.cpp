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
    int kthSmallest(TreeNode* root, int k) {
        auto* node{root};
        while (node) {
            if (!node->left) {
                k--;
                if (k == 0) return node->val;
                node = node->right;
            }
            else {
                auto* pred{node->left};
                while (pred->right && pred->right != node) {
                    pred = pred->right;
                }
                if (!pred->right) {
                    pred->right = node;
                    node = node->left;
                }
                else {
                    pred->right = nullptr;
                    k--;
                    if (k == 0) return node->val;

                    node = node->right;
                }
            }
        }
    }
};
