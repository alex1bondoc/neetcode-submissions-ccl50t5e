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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto* it{head};
        ListNode* beforeIt{new ListNode(-1)};
        auto* start{beforeIt};
        while (it) {
            auto* cur{it};
            int i{1};
            for (; cur && i < k; ++i) {
                cur = cur->next;
            }
            if (!cur) break;
            auto* prev{cur->next};
            auto* curRev{it};
            auto* nextx{cur->next};
            while (curRev && curRev != nextx) {
                auto* next{curRev->next};
                curRev->next = prev;
                prev = curRev;
                curRev = next;
            }
            beforeIt->next = prev;
            beforeIt = it;
            it = curRev;
        }
        return start->next;
    }
};
