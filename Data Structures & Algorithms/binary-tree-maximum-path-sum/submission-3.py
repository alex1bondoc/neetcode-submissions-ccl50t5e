# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.res = -float("inf")
        def dfs(node):
            if not node:
                return 0
            print(node.val)
            left = dfs(node.left) 
            right = dfs(node.right)
            l = max(left, 0)
            r = max(right, 0)
            self.res = max(self.res,l + node.val, r + node.val, left + right + node.val)
            return max(left + node.val, right + node.val)
        dfs(root)
        return self.res