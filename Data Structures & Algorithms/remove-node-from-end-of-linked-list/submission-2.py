# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        nth = head
        for i in range(n):
            nth = nth.next

        cur = head
        prev = None
        while nth:
            prev = cur
            cur = cur.next
            nth = nth.next
        if prev:
            prev.next = cur.next
        else:
            return cur.next
        return head