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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res{};
        for (auto list : lists) {
            auto dummy{new ListNode(0)};
            auto start{dummy};
            auto cur{list};
            while (cur && res) {
                if (cur->val < res->val) {
                    dummy->next = cur;
                    cur = cur->next;
                }
                else {
                    dummy->next = res;
                    res = res->next;
                }
                dummy = dummy->next;
            }
            if (cur) dummy->next = cur;
            else dummy->next = res;
            res = start->next;
            delete start;
        }
        return res;

    }
};
