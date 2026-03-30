# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        cur = root
        prev = None
        res = []
        while cur:
            if cur.left == None:
                res.append(cur.val)
                cur = cur.right
            else:
                prev = cur.left
                while prev.right is not None and prev.right is not cur:
                    prev = prev.right
                if prev.right is None:
                    prev.right = cur
                    cur = cur.left
                elif prev.right is cur:
                    prev.right = None
                    res.append(cur.val)
                    cur = cur.right
        return res