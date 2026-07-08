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
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;
        auto* slow{head->next};
        auto* fast{head->next->next};
        while (slow && fast) {
            if (slow == fast) { return true; }
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
            if (!fast) return false;
        }
        return false;
    }
};
