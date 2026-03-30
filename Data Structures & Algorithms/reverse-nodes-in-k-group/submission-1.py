# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode()
        prev = dummy
        cur = head
        while  cur:
            i = k
            kth = cur
            while kth and i > 0:
                kth = kth.next
                i -= 1
            if i == 0:
                p = None
                c = cur
                while c and c != kth:
                    n = c.next
                    c.next = p
                    p = c
                    c = n
                prev.next = p
                while prev.next:
                    prev = prev.next
                cur = kth

            else :
                prev.next = cur
                break
        return dummy.next
                 

