/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getTailNode(struct ListNode* head, int n) {
	while(n>0 && head) {
		head = head->next;
		n--;
	}
	return head;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode* node = head;
    if(node) {
    	struct ListNode* prev = NULL;
    	struct ListNode* tail_node = getTailNode(node, n);
    	while(tail_node) {
    		prev = node;
    		node = node->next;
    		tail_node = tail_node->next;
    	}
    	if(prev) {
    		prev->next = node->next;
    	}else
    	    return node->next;
    }
    return head;
}