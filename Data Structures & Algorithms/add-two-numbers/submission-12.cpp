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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* head{new ListNode(0)};
        int carry{0};
        auto* start{head};
        while (l1 && l2) {
            int sum{(l1->val + l2->val + carry) % 10};
            carry = (l1->val + l2->val + carry) / 10;
            start->next = new ListNode(sum);
            start = start->next;
            auto* next = l1->next;
            delete l1;
            l1 = next;
            next = l2->next;
            delete l2;
            l2 = next;
        }
        if (l2) l1 = l2;
        while (l1) {
            int sum{(l1->val + carry) % 10};
            carry = (l1->val + carry) / 10;
            start->next = new ListNode(sum);
            start = start->next;
            auto* next = l1->next;
            delete l1;
            l1 = next;
        }
        if (carry) {
            start->next = new ListNode(1);
        }
        auto* next = head->next;
        delete head;
        return next;
    }
};
