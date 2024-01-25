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

class Solution { // Iterative solution
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};

class Solution { // Better recursive solution
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* newHead = head;
        if (head->next != nullptr) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};

class Solution { // Recursive solution
public:
    ListNode* reverseList(ListNode* first, ListNode* second) {
        if (second != nullptr) {
            ListNode* next = second->next;
            second->next = first;
            return reverseList(second, next);
        }
        else return first;
    }

    ListNode* reverseList(ListNode* head) {
        if (head != nullptr) return reverseList(nullptr, head);
        else return head;
    }
};
