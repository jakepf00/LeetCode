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
        if (head == nullptr) return head;

        Node* cur = head->next;
        Node* prev = new Node(head->val);
        Node* newHead = prev;

        map<Node*, Node*> locations;
        locations[head] = prev;

        while (cur) {
            Node* newNode = new Node(cur->val);
            locations[cur] = newNode;
            prev->next = newNode;
            prev = newNode;
            cur = cur->next;
        }

        cur = head;
        Node* cur2 = newHead;
        while (cur) {
            if (cur->random != nullptr) {
                cur2->random = locations[cur->random];
            }
            cur = cur->next;
            cur2 = cur2->next;
        }

        return newHead;
    }
};
