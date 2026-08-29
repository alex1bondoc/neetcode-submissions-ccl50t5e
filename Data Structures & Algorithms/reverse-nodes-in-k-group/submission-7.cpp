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
        auto prec{new ListNode{0, head}};
        auto it{head};
        head = prec;
        while (it) {
            auto c{it};
            int counter{1};
            while (counter < k && c) {
                c = c->next;
                counter ++;
            }
            if (c) {
                auto groupStart{it};
                auto groupEnd{c};
                auto cur{it};
                auto nextGroupStart{c->next};
                ListNode* prev{};
                while (cur != nextGroupStart) {
                    auto next{cur->next};
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                }
                prec->next = groupEnd;
                groupStart->next = nextGroupStart;
                prec = groupStart;
                it = nextGroupStart;
            }
            else {
                prec->next = it;
                break;
            }
        } 
        return head->next;
    }
};
