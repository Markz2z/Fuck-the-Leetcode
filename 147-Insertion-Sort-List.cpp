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
    void insert(ListNode* start, ListNode* end, ListNode* insert_node) {
        ListNode* cur = start->next;
        ListNode* prev = start;
        while(cur->val < insert_node->val) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = insert_node;
        insert_node->next = cur;
    }

    ListNode* insertionSortList(ListNode* head) {
        if (!head || (head && head->next == nullptr)) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = head;
        while(cur->next != nullptr) {
            if (cur->val > cur->next->val) {
                ListNode* adjust_node = cur->next;
                cur->next = adjust_node->next;
                //adjust the linkedlist from dummy to adjust_node
                insert(dummy, cur, adjust_node);
            } else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};