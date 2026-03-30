# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        result = 1
        if root == None:
            return 0
        mp = {None: 0}
        stack = [(root, root.val)]
        while stack:
            node, maxi = stack.pop(0)
            if node.left :
                if node.left.val >= maxi:
                    result += 1
                stack.append((node.left, max(node.left.val, maxi)))
            if node.right :
                if node.right.val >= maxi:
                    result += 1
                stack.append((node.right, max(node.right.val, maxi)))

        return result