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
        auto* head{new TreeNode(0)};
        auto* cur{head};
        int i{}, j{}, n{static_cast<int>(preorder.size())};

        while (i < n && j < n) {
            cur->right = new TreeNode(preorder[i], nullptr, cur->right);
            cur = cur->right;
            i ++;
            while (i < n && cur->val != inorder[j]) {
                cur->left = new TreeNode(preorder[i++], nullptr, cur);
                cur = cur->left;
            } 
            j ++;
            while (cur->right && j < n) {
                auto* pred{cur->right};
                cur->right = nullptr;
                cur = pred;
                j++;
            }
        }

        cur = head->right;

        delete head;
        return cur;
    }
};