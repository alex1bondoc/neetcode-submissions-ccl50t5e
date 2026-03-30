# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        head = dummy
        l1 = list1
        l2 = list2
        while l1 or l2:
            if l1:
                n1 = l1.next
            if l2 :
                n2 = l2.next
            node = None
            if l1 and l2:
                if l1.val < l2.val:
                    node = l1
                    l1 = n1
                else:
                    node = l2
                    l2 = n2
            elif l1:
                node = l1
                l1 = n1
            else :
                node = l2
                l2 = n2
            head.next = node
            head = head.next
        return dummy.next