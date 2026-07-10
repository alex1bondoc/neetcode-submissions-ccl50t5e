# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        stack = [root]
        mp = {None: (0, False)}
        if root == None:
            return True
        while stack:
            node = stack[-1]
            if node.left and node.left not in mp:
                stack.append(node.left)
            elif node.right and node.right not in mp:
                stack.append(node.right)
            else :
                node  = stack.pop()
                leftHeight, leftBalanced = mp[node.left]
                rightHeight, rightBalanced = mp[node.right]

                if abs(rightHeight - leftHeight) <= 1:
                    mp[node] = (max(leftHeight, rightHeight) + 1, True)
                else :
                    mp[node] = (max(leftHeight, rightHeight) + 1, False)
        return mp[root][1]