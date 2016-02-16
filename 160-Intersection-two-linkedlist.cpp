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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	int len1 = 1;
    	int len2 = 1;
    	ListNode *pivot1 = headA;
    	ListNode *pivot2 = headB;

    	if(!headA || !headB)
    		return NULL;

    	while(pivot1->next!=NULL && pivot2->next!=NULL) {
    		pivot1 = pivot1->next;
    		pivot2 = pivot2->next;
    		len1++;
    		len2++;
    	}

    	while(pivot1->next!=NULL) {
    		pivot1 = pivot1->next;
    		++len1;
    	}

    	while(pivot2->next!=NULL) {
    		pivot2 = pivot2->next;
    		len2++;
    	}

    	if(pivot1!=pivot2)
    		return NULL;

    	if(len1>len2) {
    		while(len1>len2){
    			headA = headA->next;
    			len1--;
    		}
    	}else if(len2>len1){
    		while(len2>len1){
    			headB = headB->next;
    			len2--;
    		}
    	}

	    while(headA!=NULL){
	        if(headA==headB)
	            return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
    }
};