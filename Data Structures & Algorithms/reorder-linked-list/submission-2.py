# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        second = slow.next
        prev = slow.next = None
        while second:
            next = second.next
            second.next = prev
            prev = second
            second = next
        
        first = head
        second = prev
        while second:
            next = first.next
            next2 = second.next
            first.next = second
            second.next = next
            first = next
            second = next2
            