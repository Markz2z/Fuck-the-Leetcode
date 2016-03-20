/**
 * Author:Mingkun Zeng
 * Date:  Feb 2nd 2016
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* ptr_1 = l1;
	struct ListNode* ptr_2 = l2;
	struct ListNode* head = NULL;
	struct ListNode* current = NULL;

	//init the head pointer
	if(ptr_1 && ptr_2) {
		if(ptr_1->val > ptr_2->val) {
			head = ptr_2;
			ptr_2 = ptr_2->next;
		}else {
			head = ptr_1;
			ptr_1 = ptr_1->next;
		}
	}else if(!ptr_2 && ptr_1) {
		return ptr_1;
	}else if(!ptr_1 && ptr_2) {
		return ptr_2;
	}else{
		return NULL;
	}
	current = head;

	//merge the two linked list
	while(ptr_1 || ptr_2) {
		if(ptr_1 && ptr_2) {
			if(ptr_1->val > ptr_2->val) {
				current->next = ptr_2;
				ptr_2 = ptr_2->next;
				current = current->next;
			}else {
				current->next = ptr_1;
				ptr_1 = ptr_1->next;
				current = current->next;
			}
		}else if(!ptr_1 && ptr_2) {
			current->next = ptr_2;
			current = current->next;
			return head;
		}else if(!ptr_2 && ptr_1) {
			current->next = ptr_1;
			current = current->next;
			return head;
		}
	}
	current->next = NULL;
	return head;
}