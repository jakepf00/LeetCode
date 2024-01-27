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
class Solution { // Cleaner solution
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode;
        ListNode* tail = head;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        if (list1) tail->next = list1;
        else tail->next = list2;

        return head->next;
    }
};

class Solution { // Messy solution
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        else if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* ans = nullptr;
        if (list1->val < list2->val) {
            ans = list1;
            list1 = list1->next;
        }
        else {
            ans = list2;
            list2 = list2->next;
        }
        ListNode* cur = ans;

        while (list1 || list2) {
            if (list1 == nullptr) {
                cur->next = list2;
                break;
            }
            else if (list2 == nullptr) {
                cur->next = list1;
                break;
            }
            else {
                if (list1->val < list2->val) {
                    cur->next = list1;
                    cur = cur->next;
                    list1 = list1->next;
                }
                else {
                    cur->next = list2;
                    cur = cur->next;
                    list2 = list2->next;
                }
            }
        }

        return ans;
    }
};
