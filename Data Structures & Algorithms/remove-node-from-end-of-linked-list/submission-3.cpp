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
        auto* fast{head};
        while (fast && n) {
            fast = fast->next;
            n --;
        }
        auto* slow{head};
        ListNode* prev{nullptr};
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
            head = head->next;
        }
        return head;
    }
};
