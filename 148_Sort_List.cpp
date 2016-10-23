/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getMid(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while(head) {
            head = head->next;
            if (head) {
                head = head->next;
                prev = slow;
                slow = slow->next;
            }
        }
        if (prev) prev->next = nullptr;
        return slow;
    } 

    ListNode* mergeList(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        else if (!list2) return list1;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        while(list1) {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        while(list2) {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        return mergeList(sortList(head), sortList(mid));
    }
};