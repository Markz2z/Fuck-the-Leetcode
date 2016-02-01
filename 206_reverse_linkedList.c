/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *temp = NULL;
    struct ListNode *p = NULL;

    if(!head) 
        return NULL;
    if(!head->next)
        return head;
    
    temp = head->next;
    //insert the temp->next to the first node
    while(temp->next) {
        p = temp->next;
        temp->next = p->next;
        p->next = head->next;
        head->next = p;
    }
    p = head->next;
    temp->next = head;
    head->next = NULL;
    return p;
}
