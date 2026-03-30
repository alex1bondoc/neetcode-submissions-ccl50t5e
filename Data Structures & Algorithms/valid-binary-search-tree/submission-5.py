# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return False
        q = deque([(root, -1001, 1001)])
        while q:
            for i in range(len(q)):
                node, mini, maxi = q.popleft()
                if not (mini < node.val < maxi):
                    return False
                if node.left:
                    q.append((node.left, mini, node.val))
                if node.right:
                    q.append((node.right, node.val, maxi))

        return True
        
        