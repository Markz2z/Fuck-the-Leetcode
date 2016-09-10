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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* res_head = head;
        while (head && head->next) {
            ListNode* cur = head;
            ListNode* next = head->next;
            if (prev) {
                prev->next = next;
            } else {
                res_head = next; 
            }
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            head = cur->next;
        }
        return res_head;
    }
};
