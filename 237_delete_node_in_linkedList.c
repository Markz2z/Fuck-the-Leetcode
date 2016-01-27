/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
	struct ListNode* ptr = NULL;
    while(node->next) {
    	ptr = node;
    	node->val = node->next->val;
    	node = node->next;
    }
    ptr->next = NULL;
}