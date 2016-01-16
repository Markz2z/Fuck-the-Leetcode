#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

int getLen(struct ListNode *head) {
    int len = 0;
    while(head) {
        head = head->next;
        len++;
    }
    return len;
}

void swapValue(struct ListNode *var1, struct ListNode *var2) {
    if(var1&&var2) {
        int temp = var1->val;
        var1->val = var2->val;
        var2->val = temp;
    }
}

struct ListNode* partition(struct ListNode*head, int length) {
	struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode*));
	int count = 1;
    if(length>1) {
        int pivot = head->val;
        struct ListNode *start = head;
        struct ListNode *i;
        for(i=head->next;length>1;length--, i=i->next){
            if(i->val < pivot){
                start = start->next;
                count++;
                swapValue(i,start);
            }
        }
        swapValue(head, start);
        result->next = start;
        result->val = count;
        return result;
    }
    result->next = head;
  	result->val = head->val;
    return result;
}

struct ListNode* sortList_(struct ListNode* head, int len) {
    if(len>1 && head) {
        struct ListNode *result = partition(head, len);
        struct ListNode *location = result->next;
        int loc = result->val;
        sortList_(head, loc-1);
        sortList_(location->next, len-loc);
    }
    return head; 
}

struct ListNode* initNode(int val) {
    struct ListNode *ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(ptr){
        ptr->val = val;
        return ptr;
    }
    return NULL;
}

struct ListNode* sortList(struct ListNode* head) {
    return sortList_(head, getLen(head));
}

void main() {
    struct ListNode *n1 = initNode(4);
    struct ListNode *n2 = initNode(1);
    struct ListNode *n3 = initNode(2);
    struct ListNode *n4 = initNode(3);
    struct ListNode *n5 = initNode(5);
    struct ListNode *n6 = initNode(6);
    struct ListNode *n7 = initNode(7);
    struct ListNode *n8 = initNode(9);
    struct ListNode *n9 = initNode(8);
    struct ListNode *n10 = initNode(10);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = NULL;
    sortList(n1);
    for(struct ListNode *i=n1;i->next!=NULL;i=i->next){
        printf("%d ", i->val);
    }
    printf("/n");
}
