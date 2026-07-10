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
        auto* start{head};
        int carry{0};
        int sum{0};
        while (l1 && l2) {
            sum = (l1->val + l2->val + carry) % 10;
            carry = (l1->val + l2->val + carry) / 10;
            start->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            start = start->next;
        }
        if (!l1 && l2) l1 = l2;
        if (l1) {
            sum = (l1->val + carry) % 10;
            carry = (l1->val + carry) / 10;
            start->next = new ListNode(sum);
            start = start->next;
            l1 = l1->next;
        }
        if (carry) {
            start->next = new ListNode(1);
        }
        return head->next;
    }
};
