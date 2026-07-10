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
        while (aux && right) {
            aux = aux->next;
            right --;
        }
        ListNode* end = aux;
        aux = head;
        ListNode* prev = nullptr;
        while (aux && left > 1) {
            prev = aux;
            aux = aux->next;
            left --;
        }
        while (aux != end) {
            ListNode* next = aux->next;
            aux->next = prev;
            prev = aux;
            aux = next;
        }
        head = prev;
        while (prev->next) {
            prev = prev->next;
        }
        prev->next = aux;
        return head;
    }
};