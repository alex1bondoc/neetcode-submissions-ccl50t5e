# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None
        l1 = lists[0]
        for i in range(1, len(lists)):
            head = ListNode(0)
            aux = head
            l2 = lists[i]
            while l1 and l2:
                if l1.val > l2.val:
                    aux.next = l2
                    l2 = l2.next
                else :
                    aux.next = l1
                    l1 = l1.next
                aux = aux.next
            if l1:
                aux.next = l1
            if l2:
                aux.next = l2
            l1 = head.next
        return l1