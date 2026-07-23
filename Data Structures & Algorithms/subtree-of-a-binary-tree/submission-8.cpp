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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            auto* node{q.front()};
            q.pop();
            if (node->val == subRoot->val) {
                if (isSameTree(node, subRoot)) return true;
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st1, st2;
        st1.push(p);
        st2.push(q);
        while (st1.size()) {
            auto* node1{st1.top()};
            auto* node2{st2.top()};
            st1.pop();
            st2.pop();
            if (!node1 && !node2) continue;
            if (!node1 && node2 || node1 && !node2) return false;
            if (node1->val != node2->val) return false;
            st1.push(node1->left);
            st1.push(node1->right);
            st2.push(node2->left);
            st2.push(node2->right);
        }
        return true;
    }
};
