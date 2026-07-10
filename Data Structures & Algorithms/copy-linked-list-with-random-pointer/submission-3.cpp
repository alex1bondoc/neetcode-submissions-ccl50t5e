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
        unordered_map<Node*, Node*> map;
        auto* start{head};
        while (start) {
            map[start] = new Node(start->val);
            start = start->next;
        }
        start = head;
        while (start) {
            auto* cp{map[start]};
            if (start->next) {
                cp->next = map[start->next];
            }
            if (start->random) {
                cp->random = map[start->random];
            }
            start = start->next;
        }
        return map[head];
    }
};
