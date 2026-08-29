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
        auto it{head};
        ListNode* prec{new ListNode};
        prec->next = head;
        head = prec;
        while (it) {
            auto c{it};
            auto i = 1;
            while (i < k && c) {
                c = c->next;
                i ++;
            }
            
            if (i == k && c) {
                auto cur{it};
                auto cit{it};
                auto follow{c->next};
                auto end{c};
                ListNode* prev{};
                while (cur != follow) {
                    auto next{cur->next};
                    cur->next = prev;
                    prev = cur;
                    cur = next;
                }
                prec->next = prev;
                prec = cit;

                it = follow;
            }
            else {
                prec->next = it;
                break;
            }
        }
        prec = head->next;
        delete head;
        return prec;
    }
};
