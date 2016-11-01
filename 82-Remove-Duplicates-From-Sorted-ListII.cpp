class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head && head->next) {
            ListNode *dummy = new ListNode(-1);
            dummy->next = head;
            ListNode *unique = dummy, *cur = head;
            int prev = -100000;
            while (cur && cur->next) {
                if (cur->val != cur->next->val && cur->val!=prev) {
                    unique->next = cur;
                    unique = unique->next;
                }
                prev = cur->val;
                cur = cur->next;
            }
            unique->next = cur->val==prev? nullptr : cur;
            return dummy->next;
        }
        return head;
    }
};