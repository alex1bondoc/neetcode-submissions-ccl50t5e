# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        prev = None
        cur = l1
        while cur:
            next = cur.next
            aux = cur
            cur.next = prev
            prev = aux
            cur = next
        rl1 = prev
        prev = None
        cur = l2
        while cur:
            next = cur.next
            aux = cur
            cur.next = prev
            prev = aux
            cur = next    
        rl2 = prev
        add = 0
        sol = rl1
        while rl1 and rl2:
            rl1.val = rl1.val + rl2.val + add
            if rl1.val > 10:
                add = 1
                rl1.val = rl1.val%10
            else :
                add = 0
            prev = rl1
            rl1 = rl1.next
            rl2 = rl2.next
        if rl2:
            prev.next = rl2
            rl1 = rl2
        while rl1:
            rl1.val = rl1.val + add
            if rl1.val > 10:
                add = 1
                rl1.val = rl1.val%10
            else :
                add = 0
            prev = rl1
            rl1 = rl1.next
        if add:
            sol = ListNode(1, sol)
        prev = None
        cur = sol
        while cur:
            next = cur.next
            aux = cur
            cur.next = prev
            prev = aux
            cur = next
        return prev
