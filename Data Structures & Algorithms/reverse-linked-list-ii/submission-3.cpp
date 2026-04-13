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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* aux = head;
        ListNode* aux2 = head;
        ListNode* p = nullptr;
        while (left > 1) {
            p = aux;
            aux = aux->next;
            left --;
        }
        while (right) {
            aux2 = aux2->next;
            right--;
        }
        ListNode *prev = aux2;
        ListNode* cur = aux;
        while (cur != aux2) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (p != nullptr) {
            p->next = prev;
        }
        else {
            head = prev;
        }
        return head;
    }
};