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
    bool hasCycle(ListNode *head) {
    	ListNode *slow = head;
    	ListNode *quick = head;
    	if(head) {
    		while(quick && quick->next) {
	    		slow = slow->next;
	    		quick = quick->next;
	    		quick = quick->next;
	    		if(slow!=NULL && slow==quick){
	    			return true;
	    		}
    		}
    	}
    	return false;
    }
};