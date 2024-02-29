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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode();
        ListNode* prev = newHead;

        int num = l1->val + l2->val;
        int carry = (num >= 10);
        prev->val = num % 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 || l2) {
            if (!l1) {
                num = l2->val + carry;
                carry = (num >= 10);
                ListNode* newNode = new ListNode(num % 10);
                prev->next = newNode;
                prev = newNode;
                l2 = l2->next;
            }
            else if (!l2) {
                num = l1->val + carry;
                carry = (num >= 10);
                ListNode* newNode = new ListNode(num % 10);
                prev->next = newNode;
                prev = newNode;
                l1 = l1->next;
            }
            else {
                num = l1->val + l2->val + carry;
                carry = (num >= 10);
                ListNode* newNode = new ListNode(num % 10);
                prev->next = newNode;
                prev = newNode;
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (carry) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
        return newHead;
    }
};
