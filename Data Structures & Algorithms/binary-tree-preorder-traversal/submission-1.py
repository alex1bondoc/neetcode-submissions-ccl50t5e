# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        cur = root
        prev = None
        res = []
        while cur:
            print(cur.val)
            if cur.left == None:
                res.append(cur.val)
                cur = cur.right
            else:
                prev = cur.left
                while prev.right is not None and prev.right is not cur:
                    prev = prev.right
                if prev.right is None:
                    prev.right = cur
                    res.append(cur.val)
                    cur = cur.left
                elif prev.right is cur:
                    prev.right = None
                    cur = cur.right
        return res