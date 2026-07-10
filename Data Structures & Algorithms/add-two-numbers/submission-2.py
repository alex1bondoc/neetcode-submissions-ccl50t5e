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
        res = rl1
        prev = None
        while rl1 and rl2:
            x = rl1.val + rl2.val + add
            add = 0
            if x > 10:
                add = 1
            x = x % 10
            rl1.val = x
            prev = rl1
            rl1 = rl1.next
            rl2 = rl2.next
        while rl1 :
            rl1.val = add + rl1.val
            add = 0

            if rl1.val > 10:
                rl1.val = rl1.val%10
                add = 1
            prev = rl1
        while rl2 :
            rl2.val = add + rl2.val
            add = 0

            if rl2.val > 10:
                rl2.val = rl2.val%10
                add = 1
            prev.next = rl2
            prev = rl2
        cur = res
        prev = None
        while cur:
            next = cur.next
            aux = cur
            cur.next = prev
            prev = aux
            cur = next
        res = prev
        if add:
            prev.next = ListNode(add)
        return res
