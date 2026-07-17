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
        for (int i{}; i < n; ++i) {
            fast = fast->next;
        }
        ListNode* prev{nullptr};
        while (fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (prev) {
            auto* aux{slow->next};
            prev->next = aux;
            delete slow;
        }
        else {
            head = head->next;
            delete slow;
        }
        return head;
    }
};
