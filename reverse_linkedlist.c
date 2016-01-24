#include "stdio.h"

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* reverse_linkedList(Node* head) {
    Node *temp = NULL;
    Node *p = NULL;

    if(!head) return NULL;
    
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

Node* getNode(int val) {
    Node *node = (Node*)malloc(sizeof(Node));
    if(!node) return NULL;
    node->val = val;
    return node;
}

void main() {
    Node *n1 = getNode(1);
    Node *n2 = getNode(2);
    Node *n3 = getNode(3);
    Node *n4 = getNode(4);
    Node *n5 = getNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
   	n4->next = n5;
   	n5->next = NULL;
   	Node* ptr = reverse_linkedList(n1);;
   	while(ptr){
   		printf("%d\n", ptr->val);
   		ptr = ptr->next;
   	}
}