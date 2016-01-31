/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
	if(head){
	    struct ListNode* oddHead  = head;
	    if(head->next) {
		    struct ListNode* evenHead = head->next;
		    struct ListNode* odd_temp = oddHead;
		    struct ListNode* even_temp = evenHead;
		    head = head->next;
		    int i = 0;
		    while(head->next!=NULL) {
		    	if(i%2==0) {
		    		odd_temp->next = head->next;
		    		odd_temp = odd_temp->next;
		    		printf("%d\n", odd_temp->val);
		    	}
		    	else {
		    		even_temp->next = head->next;
		    		even_temp = even_temp->next;
		    	}
		    	head = head->next;
		    	i++;
		    }
		    odd_temp->next = evenHead;
		    even_temp->next = NULL;
		    return oddHead;
		}else
			return head;
	}
}