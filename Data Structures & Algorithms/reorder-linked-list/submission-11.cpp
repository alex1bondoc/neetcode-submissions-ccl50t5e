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
    void reorderList(ListNode* head) {
        auto* slow{head};
        auto* fast{head->next};
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto* cur{slow->next};
        slow->next = nullptr;
        ListNode* prev{nullptr};
        while (cur) {
            auto* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        auto* list1{head};
        auto* list2{prev};
        while (list1) {
            auto* next1{list1->next};
            ListNode* next2{nullptr};
            list1->next = list2;
            if (list2) {
                next2 = list2->next;
                list2->next = next1;
            }
            list1 = next1;
            list2 = next2;
        }
    }
};