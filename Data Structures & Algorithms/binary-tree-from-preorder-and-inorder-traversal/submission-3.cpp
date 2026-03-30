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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* head{new TreeNode()};
        TreeNode* cur = head;
        int i{}, j{}, n{preorder.size()};
        while (i < n && j < n) {
            cur->right = new TreeNode(preorder[i], nullptr, cur->right);
            i += 1;
            cur = cur->right;
            while (i < n && inorder[j] != cur->val) {
                cur->left = new TreeNode(preorder[i], nullptr, cur);
                i += 1;
                cur = cur->left;
            }
            j += 1;
            while (j < n && cur->right && cur->right->val == inorder[j]){
                TreeNode* prev = cur->right;
                cur->right = nullptr;
                cur = prev;
                j += 1;
            }
        }
        return head->right;
    }
};
