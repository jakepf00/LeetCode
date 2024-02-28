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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return nullptr;

        ListNode* final = head;
        for (int i = 0; i < n; i++) {
            final = final->next;
        }

        if (!final) return head->next;

        ListNode* cur = head;
        while (final->next) {
            final = final->next;
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};
