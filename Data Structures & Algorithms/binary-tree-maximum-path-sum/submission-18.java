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
    public int maxPathSum(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root;
        TreeNode last = null;
        HashMap<TreeNode, Integer> mp = new HashMap<>();
        mp.put(null, 0);
        int res = Integer.MIN_VALUE;
        while (node != null || st.size() > 0) {
            if (node != null) {
                st.push(node);
                node = node.left;
            }
            else {
                node = st.peek();
                if (node.right == last || node.right == null) {
                    st.pop();
                    int left = mp.get(node.left);
                    int right = mp.get(node.right);
                    left = Math.max(left, 0);
                    right = Math.max(right, 0);
                    res = Math.max(left + right + node.val, res);
                    int help = Math.max(left, right);
                    mp.put(node, help + node.val);
                    last = node;
                    node = null;
                }
                else {
                    node = node.right;
                }
            }
        }
        return res;
    }
}
