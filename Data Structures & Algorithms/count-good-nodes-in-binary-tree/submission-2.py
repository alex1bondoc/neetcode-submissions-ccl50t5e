# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        res = 0
        q = deque([(root, -101)])
        while q:
            for i in range(len(q)):
                node, prev = q.popleft()
                if node.val >= prev:
                    res += 1
                if node.right:
                    q.append((node.right, max(node.val, prev)))
                if node.left:
                    q.append((node.left, max(node.val, prev)))
        return res

