# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        head = ListNode(0)
        aux = head
        while l1 and l2:
            value = 0
            if l1 and l2:
                value = l1.val + l2.val
            elif l1:
                value = l1.val
            else:
                value = l2.val
            value += carry
            carry = value // 10
            value = value % 10
            head.next = ListNode(value)
            l1 = l1.next
            l2 = l2.next
            head = head.next
        while l1:
            value = l1.val
            value += carry 
            carry = value / 10
            value = value % 10
            head.next = ListNode(value)
            l1 = l1.next
            head = head.next
        while l2:
            value = l2.val
            value += carry 
            carry = value / 10
            value = value % 10
            head.next = ListNode(value)
            l2 = l2.next
            head = head.next
        if carry > 0:
            head.next = ListNode(carry)
        return aux.next         
