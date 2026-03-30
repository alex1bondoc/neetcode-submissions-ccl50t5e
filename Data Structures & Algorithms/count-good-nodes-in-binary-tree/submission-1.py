# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        res = []
        def dfs(node, prev):
            if not node:
                return
            if node:
                if node.val >=  prev:
                    res.append(node.val)
                dfs(node.left, max(prev, node.val))
                dfs(node.right, max(prev, node.val))
        dfs(root, -101)
        return len(res)
