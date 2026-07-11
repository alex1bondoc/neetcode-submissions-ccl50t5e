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
            if (!map.contains(start)) {
                map[start] = new Node(start->val);
            }
            if (start->next && !map.contains(start->next)) {
                map[start->next] = new Node(start->next->val);
            }
            if (start->random && !map.contains(start->random)) {
                map[start->random] = new Node(start->random->val);
            }
            map[start]->next = map[start->next];
            map[start]->random = map[start->random];

            start = start->next;
        }
        return map[head];
    }
};
