/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head) {
        struct ListNode* temp_ptr = head;
        struct ListNode* current = head->next;
        while(current!=NULL) {
            if(current->val==temp_ptr->val) {
                temp_ptr->next = current->next;
            }else{
                temp_ptr = current;
            }
            current = current->next;
        }
    }
    return head;
}