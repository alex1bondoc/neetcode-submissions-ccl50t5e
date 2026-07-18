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
        std::priority_queue<int> pq;
        for (auto* list : lists) {
            while (list) {
                pq.push(list->val);
                list = list->next;
            }
        }
        while (!pq.empty()) {
            int val{pq.top()};
            pq.pop();
            res = new ListNode(val, res);
        }
        return res;
    }
};
