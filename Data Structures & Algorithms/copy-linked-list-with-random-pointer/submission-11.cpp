/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        auto* cur{head};
        while (cur) {
            auto* cp{new Node(cur->val)};
            cp->next = cur->next;
            cur->next = cp;
            cur = cp->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        auto* newHead{head->next};
        auto* curCopy{head->next};
        cur = head;
        while (cur) {
            auto* next = curCopy->next;
            if (next)
                curCopy->next = next->next;
            cur->next = next;
            cur = cur->next;
            curCopy = curCopy->next;
        }
        return newHead;
    }
};
