# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        temp = []
        q = [root]
        v = []
        sol = []
        while len(q) > 0: 
            x = q.pop(0)
            if x != None:    
                print(x.val)
                v.append(x.val)
                temp.append(x.left)
                temp.append(x.right)
            if len(q) == 0:
                if len(v) > 0: 
                    sol.append(v)
                q = temp
                temp = []
                v = []
        return sol