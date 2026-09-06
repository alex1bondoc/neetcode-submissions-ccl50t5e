/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public int kthSmallest(TreeNode root, int k) {
        TreeNode node = root;
        while (node != null) {
            if (node.left == null) {
                k --;
                if (k == 0) return node.val;
                node = node.right;
            }
            else {
                TreeNode pred = node.left;
                while (pred.right != null && pred.right != node) {
                    pred = pred.right;
                }
                if (pred.right == null) {
                    pred.right = node;
                    node = node.left;
                }
                else {
                    pred.right = null;
                    k--;
                    if (k == 0) return node.val;
                    node = node.right;
                }
            }
        }
        return -1;
    }
}
