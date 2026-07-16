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
        ListNode* res{nullptr};
        for (auto* list : lists) {
            auto* aux{new ListNode(-1)};
            auto* start{aux};
            while (res && list) {
                if (res->val < list->val) {
                    start->next = res;
                    res = res->next;
                }
                else {
                    start->next = list;
                    list = list->next;
                }
                start = start->next;
            }
            if (list) res = list;
            start->next = res;
            res = aux->next;
            delete aux;
        }
        return res;
    }
};
