# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        cur = root
        res = []
        while cur:
            print(cur.val)
            if cur.right is None:
                res.append(cur.val)
                cur = cur.left
            else:
                prev = cur.right
                while prev.left is not None and prev.left is not cur:
                    prev = prev.left
                if prev.left is None:
                    prev.left = cur
                    res.append(cur.val)
                    cur = cur.right
                else:
                    prev.left = None
                    cur = cur.left
        res.reverse()
        return res