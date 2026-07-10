# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        curr= root
        stack = []
        res = []
        while stack or curr:
            print(curr.val)
            if stack:
                curr = stack.pop()
            if curr.right:
                stack.append(curr.right)
            while curr.left != None:
                stack.append(curr.left)
                left = curr.left
                curr.left = None
                curr = left
            print([(da.val, da.left) for da in stack])
            res.append(curr.val)
            if len(res) == k:
                return res[-1]
            
        return -1