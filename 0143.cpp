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

class Solution { // O(n) time and O(1) memory
public:
    void reorderList(ListNode* head) {
        // Find midpoint + split list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        // Reverse second half of list
        ListNode* prev = nullptr;
        while (second) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // Merge lists
        second = prev;
        while(second) {
            ListNode* temp1 = head->next;
            ListNode* temp2 = second->next;
            head->next = second;
            second->next = temp1;
            head = temp1;
            second = temp2;
        }
    }
};

class Solution { // Much better - O(n) time and memory
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> list;
        ListNode* temp = head;
        while (head) {
            list.push_back(head);
            head = head->next;
        }
        
        while (list.size() > 2) {
            list[0]->next = list[list.size() - 1];
            list[list.size() - 2]->next = nullptr;
            list[list.size() - 1]->next = list[1];
            list.pop_front();
            list.pop_back();
        }
    }
};

class Solution { // Terrible solution - O(n^2)
public:
    void reorderList(ListNode* head) {
        while (head->next && head->next->next) {
            ListNode* right = head->next;
            ListNode* left = head;
            while (right->next) {
                right = right->next;
                left = left->next;
            }

            ListNode* temp = head->next;
            head->next = right;
            right->next = temp;
            left->next = nullptr;
            head = temp;
        }
    }
};
