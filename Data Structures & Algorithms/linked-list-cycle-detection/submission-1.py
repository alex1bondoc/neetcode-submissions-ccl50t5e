# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head
        while slow != None and fast != None:
            slow = slow.next
            fast = fast.next
            if slow == None:
                return False
            if fast.next == None:
                return False
            else :
                fast = fast.next
            if slow == fast:
                return True