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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* slow{head};
        auto* fast{head};
        ListNode* prev{nullptr};
        for (int i{}; i < n; ++i) {
            fast = fast->next;
        }
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {
            prev->next = slow->next;
            delete slow;
        }
        else {
            prev = head;
            head = head->next;
            delete prev;
        }
        return head;
    }
};
