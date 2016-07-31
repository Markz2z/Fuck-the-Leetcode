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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* head1 = head;
        ListNode* head2 = getMid(head);
        head1 = sortList(head1);
        head2 = sortList(head2);
        return merge(head1, head2);
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(head1 && head2) {
            if(head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
            }else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
            tail->next = NULL;
        }
        if(head1 != NULL)
            tail->next = head1;
        if(head2 != NULL)
            tail->next = head2;
        return dummy->next;
    }
    ListNode* getMid(ListNode* head) {
        //guaranteed that at least two nodes
        ListNode* fast = head->next;
        ListNode* slow = head->next;
        ListNode* prev = head;
        while(true) {
            if(fast != NULL)
                fast = fast->next;
            else
                break;
            if(fast != NULL)
                fast = fast->next;
            else
                break;
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;  // cut
        return slow;
    }
};