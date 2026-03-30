# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        add = 0
        sol = ListNode(0)
        aux = sol
        while l1 or l2 or add:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0

            val = x + y + add
            if val >= 10:
                add = 1
                val = val%10
            else :
                add = 0
            sol.next  = ListNode(val)
            sol = sol.next
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return aux.next
