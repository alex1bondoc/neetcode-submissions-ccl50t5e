# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maximum = -float("inf")
        def dfs(root):
            if not root:
                return 0
            maxSumLeft = dfs(root.left)
            maxSumRight = dfs(root.right)

            leftMax = max(0, maxSumLeft)
            rightMax = max(0, maxSumRight)
            self.maximum = max(self.maximum, root.val + leftMax + rightMax)
            return root.val + max(leftMax, rightMax)
        dfs(root)
        return self.maximum