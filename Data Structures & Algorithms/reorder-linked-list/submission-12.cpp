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
            auto* next{cur->next};
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        auto* l1{head};
        auto* l2{prev};
        while (l1) {
            auto* next{l1->next};
            l1->next = l2;
            if (l2) {
                auto* next2{l2->next};
                l2->next = next;
                l2 = next2;
            }
            l1 = next;
        }
    }
};
