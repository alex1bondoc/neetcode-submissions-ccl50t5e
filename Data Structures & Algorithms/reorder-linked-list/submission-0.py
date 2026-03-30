# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = head.next
        while fast is not None and fast.next is not None:
            slow = slow.next
            fast = fast.next.next
        l2 = slow.next
        prev = None
        slow.next = None
        cur = l2
        while cur:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        l2 = prev
        l1 = head
        while l2:
            t = l1.next
            t2 = l2.next
            l1.next = l2
            l2.next = t
            l1 = t
            l2 = t2


        