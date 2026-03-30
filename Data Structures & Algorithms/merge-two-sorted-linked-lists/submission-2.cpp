/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *c1 = list1;
        ListNode *c2 = list2;
        ListNode dummy(0);
        ListNode *node = &dummy;
        while (c1 && c2) {
            ListNode *n1 = c1 -> next;
            ListNode *n2 = c2 -> next;
            if (c1-> val <= c2 -> val) {
                node->next = c1;
                c1 = c1->next;
            }
            else {
                node->next = c2;
                c2 = c2->next;
            }
            node = node->next;
        }
        if (c1) {
            node->next = c1;
        }
        else node->next = c2;
        return dummy.next;
    }
};
