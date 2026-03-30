# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue = [(root, 0)]
        result = []
        if root == None:
            return []
        while queue:
            node, height = queue.pop(0)
            if node.left :
                queue.append((node.left, height + 1))
            if node.right: 
                queue.append((node.right, height + 1))
            if len(queue) == 0:
                result.append(node.val)
            elif queue[0][1] > height:
                result.append(node.val)
        return result