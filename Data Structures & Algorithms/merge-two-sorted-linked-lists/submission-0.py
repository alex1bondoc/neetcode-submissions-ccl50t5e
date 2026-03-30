# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        head = ListNode(-1)
        aux = head
        while list1 != None and list2 != None:
            if list1.val < list2.val:
                aux.next = ListNode(list1.val)
                list1 = list1.next
            else :
                aux.next = ListNode(list2.val)
                list2 = list2.next
            aux = aux.next
        
        while list1 != None:
            aux.next = ListNode(list1.val)
            list1 = list1.next
            aux = aux.next
        while list2 != None:
            aux.next = ListNode(list2.val)
            list2 = list2.next
            aux = aux.next    
        return head.next
