#include "stdio.h"
#include "stdlib.h"

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

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
		if(ptr_1!=NULL && ptr_2!=NULL) {
			//printf("%d %d\n", ptr_1->val, ptr_2->val);
			if(ptr_1->val > ptr_2->val) {
				current->next = ptr_2;
				ptr_2 = ptr_2->next;
				current = current->next;
			}else {
				current->next = ptr_1;
				ptr_1 = ptr_1->next;
				current = current->next;
			}
		}else if(ptr_1==NULL && ptr_2!=NULL) {
			current->next = ptr_2;
			current = current->next;
			return head;
		}else if(ptr_2==NULL && ptr_1!=NULL) {
			current->next = ptr_1;
			current = current->next;
			return head;
		}
	}
	current->next = NULL;
	return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
	int i = 0, j = 0;
    while(listsSize>1) {
	    for(i=0, j=0;i<listsSize-1;i+=2,++j) {
	    	printf("-\n");
	    	lists[j] = mergeTwoLists(lists[i], lists[i+1]);
	    }
	    if(listsSize%2) {
    	    lists[listsSize/2] = lists[listsSize-1];
	    }
	    listsSize = listsSize/2 + listsSize%2;
    }
    return lists[0];
}

ListNode* getNode(int val) {
	ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->val = val;
	ptr->next = NULL;
	return ptr;
}

void print(ListNode* head) {
	while(head) {
		printf("%d\n", head->val);
		head = head->next;
	}
}

int main() {
	ListNode* node1 = getNode(2);
	ListNode* node3 = getNode(-1);
	ListNode** lists = (ListNode**)malloc(sizeof(int)*3);
	lists[0] = node1;
	lists[1] = NULL;
	lists[2] = node3;
	node1 = mergeKLists(lists, 3);
	//node1 = mergeTwoLists(node1, node3);
	print(node1);
	return 1;
}
