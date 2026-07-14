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
            auto* next{cur->next};
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        while (cur) {
            if (cur->random != nullptr) {                
                cur->next->random = cur->random->next;
                std::cout << cur->random->val <<" " << cur->next->random->val<< endl; 
            }
            cur = cur->next->next;
        }
        auto* deepCopy{head->next};
        auto* aux{deepCopy};
        cur = head;
        while (cur) {
            auto* next{cur->next->next};
            if (next)
                aux->next = next->next;
            cur->next = next;
            cur = cur->next;
            aux = aux->next;
        }

        return deepCopy;
    }
};